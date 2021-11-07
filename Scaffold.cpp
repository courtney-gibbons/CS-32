#include "provided.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ScaffoldImpl
{
public:
    ScaffoldImpl(int nColumns, int nLevels);
    int cols() const;
    int levels() const;
    int numberEmpty() const;
    int checkerAt(int column, int level) const;
    void display() const;
    bool makeMove(int column, int color);
    int undoMove();
private:
    int m_columns;
    int m_levels;
    vector<vector<char>> m_grid;
    stack<char> m_rowStack;
    stack<char> m_colStack;
};

ScaffoldImpl::ScaffoldImpl(int nColumns, int nLevels)
{
    // Construct a Scaffold with the indicated number of columns and
    // levels. If either is not positive, you may terminate the program
    // after writing a message to cerr.
    if (nColumns < 1) {
        cerr << "Invalid columns!" << endl;
        exit(1);
    }
    if (nLevels < 1) {
        cerr << "Invalid levels!" << endl;
        exit(1);
    }
    m_columns = nColumns;
    m_levels = nLevels;
    
    // create a grid with a 2d vector
    // create levels+1 rows in our 2d vector
    // this gives us an extra row so we can leave the 0th row empty
    // and start accessing the grid at row 1
    // fill each row with a vector of columns+1 spaces
    // this gives us an extra column so we can leave the 0th column empty
    // and start accessing the grid at row 1
    for (int rowNumber = 0; rowNumber <= m_levels; rowNumber++) {
        vector<char> column(m_columns+1, ' ');
        m_grid.push_back(column);
    }
}

int ScaffoldImpl::cols() const
{
    // Return the number of columns in the scaffold.
    return ( m_columns );
}

int ScaffoldImpl::levels() const
{
    // Return the number of levels in the scaffold.
    return ( m_levels );
}

int ScaffoldImpl::numberEmpty() const
{
    // Return the number of positions in the scaffold not occupied by a checker.
    // loop through the grid
    // increment for each vacant spot
    int emptyCount = 0;
    for (int rowNumber = m_levels; rowNumber >= 1; rowNumber--) {
        for (int colNumber = m_columns; colNumber >= 1; colNumber--) {
            if (checkerAt(colNumber, rowNumber) == VACANT) {
                emptyCount++;
            }
        }
    }
    return( emptyCount );
}

int ScaffoldImpl::checkerAt(int column, int level) const
{
    // If there is a red checker at the indicated column and level, return
    // RED; if there's a black checker there, return BLACK; otherwise, return VACANT.
    
    // check to see if we're looking out of bounds
    if (level > m_levels || level < 1) {
        return VACANT;
    }
    if (column > m_columns || column < 1) {
        return VACANT;
    }
    
    // identify the character at that location in the grid
    switch (m_grid[level][column]) {
        case 'R':
            return RED;
            break;
        case 'B':
            return BLACK;
            break;
        case ' ':
            return VACANT;
            break;
        default:
            return VACANT;
            break;
    }
}

void ScaffoldImpl::display() const
{
    // Display the scaffold to the screen in the following manner:
    // Display the levels of the scaffold from highest to lowest.
    // Display each red checker as an R.
    // Display each black checker as a B.
    // Display each vacant cell as a space character.
    // Display a - (hyphen) character below level 1 of each column.
    // Display the side of each column as a | character.
    // Display the joints between the bottom of the column and the sides of
    // the columns as + characters.
    
    for (int rowNumber = m_levels; rowNumber >= 1; rowNumber--) {
        for (int colNumber = m_columns; colNumber >= 1; colNumber--) {
            // because of the way the 2d vector is configured,
            // the columns start with the first index at the right, not the left
            // when we edit the grid, it's fine to have it reversed
            // but we must fix this when we display
            // display m_columns-colNumber+1 to fix this
            cout << "|" << m_grid[rowNumber][m_columns-colNumber+1];
        }
        cout << "|" << endl;
    }
    for (int i = 1; i <= m_columns; i++) {
        cout << "+";
        cout << "-";
    }
    cout << "+" << endl;
}

bool ScaffoldImpl::makeMove(int column, int color)
{
    // If the first parameter is a valid column number with at least one
    // vacant position in that column, and if color is RED or BLACK, drop a
    // checker of the appropriate color into that column and return true.
    // Otherwise, do nothing and return false.
    
    // make sure column is valid
    if (column > m_columns || column < 1) {
        return false;
    }
    
    // make sure the column has at least 1 empty position
    if (m_grid[m_levels][column] != ' ') {
        return false;
    }
    
    // make sure our color is valid
    if (color != RED && color != BLACK) {
        return false;
    }
    
    // loop through the rows until we find the first empty one
    for (int rowNumber = 1; rowNumber <= m_levels; rowNumber++) {
        if (m_grid[rowNumber][column] == ' ') {
            // keep track of the row and column we just made our move in so we can undo later
            m_rowStack.push(rowNumber);
            m_colStack.push(column);
            // update the grid with our color
            switch (color) {
                case RED:
                    m_grid[rowNumber][column] = 'R';
                    break;
                case BLACK:
                    m_grid[rowNumber][column] = 'B';
                    break;
            }
            break;
        }
    }
    return true;
}

int ScaffoldImpl::undoMove()
{
    // Undo the most recently made move that has not already been undone
    // (i.e., remove the checker in the scaffold that was most recently
    // added), and return the number of the column from which that checker
    // was removed. If there are no checkers in the scaffold, do nothing and
    // return 0.
    
    // check if we have no moves left to undo
    if (m_colStack.empty() || m_rowStack.empty()) {
        return 0;
    }
    
    // otherwise, look at the top of the stack, which is the last move added
    // pop the stack
    // make the corresponding location on the grid vacant again
    else {
        int row = m_rowStack.top();
        m_rowStack.pop();
        int col = m_colStack.top();
        m_colStack.pop();
        m_grid[row][col] = ' ';
        return ( col );
    }
}

//******************** Scaffold functions *******************************

//  These functions simply delegate to ScaffoldImpl's functions.
//  You probably don't want to change any of this code.

Scaffold::Scaffold(int nColumns, int nLevels)
{
    m_impl = new ScaffoldImpl(nColumns, nLevels);
}

Scaffold::~Scaffold()
{
    delete m_impl;
}

Scaffold::Scaffold(const Scaffold& other)
{
    m_impl = new ScaffoldImpl(*other.m_impl);
}

Scaffold& Scaffold::operator=(const Scaffold& rhs)
{
    if (this != &rhs)
    {
        Scaffold temp(rhs);
        swap(m_impl, temp.m_impl);
    }
    return *this;
}

int Scaffold::cols() const
{
    return m_impl->cols();
}

int Scaffold::levels() const
{
    return m_impl->levels();
}

int Scaffold::numberEmpty() const
{
    return m_impl->numberEmpty();
}

int Scaffold::checkerAt(int column, int level) const
{
    return m_impl->checkerAt(column, level);
}

void Scaffold::display() const
{
    m_impl->display();
}

bool Scaffold::makeMove(int column, int color)
{
    return m_impl->makeMove(column, color);
}

int Scaffold::undoMove()
{
    return m_impl->undoMove();
}

