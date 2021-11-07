#include <iostream>
//#include <string>
//#include <random>
//#include <utility>
#include <cstdlib>

#include "History.h"
#include "globals.h"

using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    
    // generate 2D array of maxrows and maxcols as a member variable
    // only fill in the part of the array corresponding to the size of the city
    for (int r = 0; r < m_rows; r++) {
        for (int c = 0; c < m_cols; c++) {
            m_grid[r][c] = '.';
        }
    }
}

bool History::record(int r, int c) {
    if (!(r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols)) {
        return false;
    }
    
    // if it's the first time we're recording the history of this spot . => A
    // else, A => B, B => C, etc. by incrementing ASCII value
    // once we hit Z, don't increment anymore
    switch (m_grid[r-1][c-1]) {
        case '.': m_grid[r-1][c-1] = 'A'; break;
        case 'Z': m_grid[r-1][c-1] = 'Z'; break;
        default: m_grid[r-1][c-1]++; break;
    }
    
    return true;
}

void History::display() const {
    clearScreen();
    
    // only print out the part of the array corresponding to the size of the city
    for (int r = 0; r < m_rows; r++) {
        for (int c = 0; c < m_cols; c++) {
            cout << m_grid[r][c];
        }
        cout << endl;
    }
    
    cout << endl;
}
