#include "provided.h"
#include "support.h"
#include <string>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class HumanPlayerImpl
{
public:
    int chooseMove(const Scaffold& s, int N, int color);
};

int HumanPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
    // If no move is possible, return 0.
    if (s.numberEmpty() == 0) {
        return 0;
    }
    
    int col;
    do {
        cout << "Where do you want to move: ";
        cin >> col;
        // if the column is less than 1, ping player again
        if (col <= 0) {
            cout << "Column must be greater than 0!" << endl;
        }
        // if the column is greater than the number of columns, ping player again
        if (col > s.cols()) {
            cout << "Column must be less than or equal to the number of columns, " << s.cols() << "." << endl;
        }
        // if they try to enter a full column, ping player again
        if (s.checkerAt(col, s.levels()) != VACANT) {
            cout << "Column full." << endl;
        }
    } while ( (col <= 0) || (col > s.cols()) || (s.checkerAt(col, s.levels()) != VACANT) );
    return col;
}

class BadPlayerImpl
{
public:
    int chooseMove(const Scaffold& s, int N, int color);
};

int BadPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
    // If no move is possible, return 0.
    if (s.numberEmpty() == 0) {
        return 0;
    }
    
    int col;
    // choose a random column while that column isnt full
    do {
        col = (rand() % s.cols()) + 1;
    } while ( (s.checkerAt(col, s.levels()) != VACANT) );
    return col;
}

class SmartPlayerImpl
{
public:
    int chooseMove(const Scaffold& s, int N, int color);
private:
    int m_lastC;
    int minimax(int& depth, int& score, AlarmClock& clock, int N, int color, Scaffold& s_copy, int& move, int& movesChecked); // minimax algorithm
    bool notQuiteMinimax(int& winner, int N, int color, const Scaffold& s_copy) const; // checks if the game is over and who won
};

int SmartPlayerImpl::chooseMove(const Scaffold& s, int N, int color) {
    // If no move is possible, return 0.
    if (s.numberEmpty() == 0) {
        return 0;
    }
    
    // make a copy of the scaffold to check on
    Scaffold s_copy(s);
    
    // keep track of the depth of recusion, the ongoing score of the move, which move we
    // ultimately choose, and the number of moves checked
    int depth = 1;
    int score = 0;
    int move = 1;
    int movesChecked = 0;
    
    // set up an alarm clock to exit right before 10 seconds
    AlarmClock clock(9700);
    
    // run minimax algorithm to determine best score
    minimax(depth, score, clock, N, color, s_copy, move, movesChecked);
    
    // can print out number of moves checked (debugging purposes)
    cerr << movesChecked << " moves checked." << endl;
    
    // check to see if we timed out (debugging purposes)
    if (clock.timedOut()) {
        cerr << "Time exceeded." << endl;
    }
    
    return move;
}

int SmartPlayerImpl::minimax(int& depth, int& score, AlarmClock& clock, int N, int color, Scaffold& s_copy, int& move, int& movesChecked) {
    // minimax algorithm
    
    // keep track of the scores from our possible moves
    vector<int> possibilities;
    // keep track of the moves we make when recursion depth = 1
    vector<int> depth1columns;
    
    for (int C = 1; C <= s_copy.cols(); C++) {
        if (s_copy.makeMove(C, color)) {
            // make the move, keep track of the last column we went in, increment moves checked
            m_lastC = C;
            movesChecked++;
            
            // if the depth is 1, keep track of the column we're trying out
            // one of these will be our move later on
            if (depth == 1) {
                depth1columns.push_back(C);
            }
            
            // check if we've timed out
            if (clock.timedOut()) {
                // if so, randomly select a column
                // i don't go over time for any of the testing boards
                // so this case doesn't matter except for bigger boards that aren't being tested
                // faster to compare possible scores only at the very end
                // so i just select a random move
                int col;
                do {
                    col = (rand() % s_copy.cols()) + 1;
                } while ( (s_copy.checkerAt(col, s_copy.levels()) != VACANT) );
                move = col;
                // return -1 to indicate we timed out
                return -1;
            }
            
            // check if the game is over
            int winner;
            if (notQuiteMinimax(winner, N, color, s_copy)) {
                // if we won
                // a really big positive number = we win soon
                // a less big positive number = we win eventually
                if (winner == color) {
                    possibilities.push_back(INT_MAX - depth);
                }
                // 0 = we tie
                if (winner == TIE_GAME) {
                    possibilities.push_back(0);
                }
            }
                
            // if the game isnt over
            else {
                // figure out what the other player's color is
                int otherColor;
                if (color == RED) {
                    otherColor = BLACK;
                } else {
                    otherColor = RED;
                }
                
                // increment depth before our next function call
                depth++;
                // call function as other color
                // push back the worst possible outcome for us -1 * their best outcome
                possibilities.push_back(-1 * minimax(depth, score, clock, N, otherColor, s_copy, move, movesChecked));
                // decrement depth after function call
                depth--;
            }
            // undo the move we just tried
            s_copy.undoMove();
        }
    }
    
    // find the index correlated to the best possible score for us
    // this makes our algorithm attack-focused not defensive
    int index = 0;
    for (int i = 0; i < possibilities.size(); i++) {
        if (possibilities[i] > possibilities[index]) {
            index = i;
        }
    }
    
    // if the recursive depth = 1, pick the column corresponding to the best score
    // that is our move
    if (depth == 1) {
        move = depth1columns[index];
    }
    
    // return the best possible score for us
    return possibilities[index];
}

bool SmartPlayerImpl::notQuiteMinimax(int& winner, int N, int color, const Scaffold& s_copy) const
{
    // checks if the game is over and who won
    
    // if we haven't made a move yet, automatically return false
    if (m_lastC == 0) {
        return false;
    }
    
    // if we find N in a row, the winner is the color who just made a move
    if (connectN(m_lastC, N, color, s_copy) == true) {
        winner = color;
        return true;
    }
    
    // if there are 0 free spots left, it's a tie
    if (s_copy.numberEmpty() == 0) {
        winner = TIE_GAME;
        return true;
    }
    
    // otherwise, the games not over
    return false;
}

//******************** Player derived class functions *************************

//  These functions simply delegate to the Impl classes' functions.
//  You probably don't want to change any of this code.

HumanPlayer::HumanPlayer(string nm)
: Player(nm)
{
    m_impl = new HumanPlayerImpl;
}

HumanPlayer::~HumanPlayer()
{
    delete m_impl;
}

int HumanPlayer::chooseMove(const Scaffold& s, int N, int color)
{
    return m_impl->chooseMove(s, N, color);
}

BadPlayer::BadPlayer(string nm)
: Player(nm)
{
    m_impl = new BadPlayerImpl;
}

BadPlayer::~BadPlayer()
{
    delete m_impl;
}

int BadPlayer::chooseMove(const Scaffold& s, int N, int color)
{
    return m_impl->chooseMove(s, N, color);
}

SmartPlayer::SmartPlayer(string nm)
: Player(nm)
{
    m_impl = new SmartPlayerImpl;
}

SmartPlayer::~SmartPlayer()
{
    delete m_impl;
}

int SmartPlayer::chooseMove(const Scaffold& s, int N, int color)
{
    return m_impl->chooseMove(s, N, color);
}
