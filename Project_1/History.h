#ifndef History_h
#define History_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

class City;

#include "globals.h"

class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
      private:
        int m_rows = 0;
        int m_cols = 0;
        char m_grid[MAXROWS][MAXCOLS];
    };

#endif
