#include "provided.h"
#include "support.h"
#include <iostream>
using namespace std;

class GameImpl
{
public:
    GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black);
    bool completed(int& winner) const;
    bool takeTurn();
    void play();
    int checkerAt(int c, int r) const;
private:
    Scaffold* m_scaffold;
    int m_N;
    int m_turn;
    Player* m_red;
    Player* m_black;
    int m_lastC;
};

GameImpl::GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black)
{
    // Construct a Game to be played with the indicated players on a scaffold of the
    // indicated size. The red player always moves first. The goal of the game is for a
    // player to get N of their checkers in a row.
    
    // create a new scaffold, store N, store the players, store whose turn it is (RED)
    m_scaffold = new Scaffold(nColumns, nLevels);
    m_N = N;
    m_red = red;
    m_black = black;
    m_turn = RED;
    
    // set the last column we went in to 0 - not possible - easily check for this and return in completed
    m_lastC = 0;
}

bool GameImpl::completed(int& winner) const
{
    // If the game isn't over (i.e., more moves are possible), return false and do not
    // change winner. Otherwise, set winner to RED, BLACK, or TIE_GAME, reflecting the
    // outcome of the game, and return true.
    
    // check if we just created the game and the last column we went in is 0
    if (m_lastC == 0) {
        return false;
    }
    
    // if it's about to be red's turn, check if black just won
    if (m_turn == RED) {
        if (connectN(m_lastC, m_N, BLACK, *m_scaffold) == true) {
            winner = BLACK;
            return true;
        }
    }
        
    // if it's about to be black's turn, check if red just won
    else {
        if (connectN(m_lastC, m_N, RED, *m_scaffold) == true) {
            winner = RED;
            return true;
        }
    }
    
    // if no one's won, check if the gameboard is full - tie
    if (m_scaffold->numberEmpty() == 0) {
        winner = TIE_GAME;
        return true;
    }
    
    // otherwise, game's not over
    return false;
}

bool GameImpl::takeTurn()
{
    // If the game is over, return false. Otherwise, make a move for the player whose turn
    // it is (so that it becomes the other player's turn) and return true.
    
    int winner = TIE_GAME;
    // if the game's over, return false and don't make any moves
    if (completed(winner) == true) {
        return false;
    }
    
    // if it's red's turn
    // have red choose their move
    // store their move in lastC
    // make the move on the scaffold
    // set the turn to black
    if (m_turn == RED) {
        int column = m_red->chooseMove(*m_scaffold, m_N, RED);
        m_lastC = column;
        m_scaffold->makeMove(column, RED);
        m_turn = BLACK;
        return true;
    }
    
    // if it's black's turn
    // have black choose their move
    // store their move in lastC
    // make the move on the scaffold
    // set the turn to red
    if (m_turn == BLACK) {
        int column = m_black->chooseMove(*m_scaffold, m_N, BLACK);
        m_lastC = column;
        m_scaffold->makeMove(column, BLACK);
        m_turn = RED;
        return true;
    }
    
    return false;
}

void GameImpl::play()
{
    // Play the game. Display the progress of the game in a manner of your choosing,
    // provided that someone looking at the screen can follow what's happening. If neither
    // player is interactive, then to keep the display from quickly scrolling through the
    // whole game, it would be reasonable periodically to prompt the viewer to press ENTER
    // to continue and not proceed until ENTER is pressed. (The ignore member function for
    // input streams is useful here.) Announce the winner at the end of the game.
    
    // say whose playing, what color they are, and display an empty scaffold
    cout << m_red->name() << " vs. " << m_black->name() << " in a game of Connect " << m_N << "!" << endl;
    cout << m_red->name() << " is red (R). " << m_black->name() << " is black (B)." << endl;
    cout << "Let the game commence." << endl << endl;
    m_scaffold->display();
    cout << endl;
    
    // while the game isn't over
    int winner = TIE_GAME;
    while (completed(winner) == false) {
        // if it's red's turn, have them take their turn
        if (m_turn == RED) {
            cout << "It's " << m_red->name() << "'s turn." << endl;
            takeTurn();
            cout << m_red->name() << " has determined their next move." << endl;
            // if both players aren't human, you must press enter to see their moves
            // otherwise the game happens at LIGHT SPEED and it's hard to follow along
            if (m_red->isInteractive() == false && m_black->isInteractive() == false) {
                cout << "Press enter to continue.";
                string temp;
                getline(cin, temp);
            }
            cout << endl;
            m_scaffold->display();
            cout << endl;
        }
            
        // if it's black's turn, have them take their turn
        else {
            cout << "It's " << m_black->name() << "'s turn." << endl;
            takeTurn();
            cout << m_black->name() << " has determined their next move." << endl;
            // if both players aren't human, you must press enter to see their moves
            // otherwise the game happens at LIGHT SPEED and it's hard to follow along
            if (m_red->isInteractive() == false && m_black->isInteractive() == false) {
                cout << "Press enter to continue.";
                string temp;
                getline(cin, temp);
            }
            cout << endl;
            m_scaffold->display();
            cout << endl;
        }
    }
    
    // once the game as ended, announce the winner or tie
    cout << "Game over!" << endl;
    if (winner == RED) {
        cout << m_red->name() << " won!" << endl;
    }
    else if (winner == BLACK) {
        cout << m_black->name() << " won!" << endl;
    }
    else if (winner == TIE_GAME) {
        cout << "Tie game!" << endl;
    }
    
    // delete scaffold bc we dynamically allocated it!
    delete m_scaffold;
}

int GameImpl::checkerAt(int c, int r) const
{
    // In the Game's scaffold, if there is a red checker at the indicated column and level,
    // return RED; if there's a black checker there, return BLACK; otherwise, return VACANT.
    // This function exists so that we and you can more easily test your program; a real
    // client would never use it.
    
    return m_scaffold->checkerAt(c, r);
}

//******************** Game functions *******************************

//  These functions simply delegate to GameImpl's functions.
//  You probably don't want to change any of this code.

Game::Game(int nColumns, int nLevels, int N, Player* red, Player* black)
{
    m_impl = new GameImpl(nColumns, nLevels, N, red, black);
}

Game::~Game()
{
    delete m_impl;
}

bool Game::completed(int& winner) const
{
    return m_impl->completed(winner);
}

bool Game::takeTurn()
{
    return m_impl->takeTurn();
}

void Game::play()
{
    m_impl->play();
}

int Game::checkerAt(int c, int r) const
{
    return m_impl->checkerAt(c, r);
}
