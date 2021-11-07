#include "support.h"
#include "provided.h"

bool connectN(int C, int N, int color, const Scaffold& s_copy) {
    // checks if we have N in a row
    
    // figure out what row we just went in
    // for the column we just made our move in, find the first vacant row
    // if the column is full, it'll stop at the last row
    // then subtract 1 to see where we just went
    int rowNumber;
    for (rowNumber = 1; rowNumber <= s_copy.levels(); rowNumber++) {
        if (s_copy.checkerAt(C, rowNumber) == VACANT) {
            break;
        }
    }
    int R = rowNumber-1;

    // initialize iterators
    int r;
    int c;
    
    // NORTH - SOUTH
    // set r, c iterators back to R, C
    // while it's still our color, go as far north as possible
    // then check if we have N in a row south from that point
    r = R;
    c = C;
    while (s_copy.checkerAt(c, r+1) == color) {
        r++;
    }
    if (South(c, r, N, color, s_copy) == true) {
        return true;
    }

    // NORTH-EAST - SOUTH-WEST
    // set r, c iterators back to R, C
    // while it's still our color, go as far north-east as possible
    // then check if we have N in a row south-west from that point
    r = R;
    c = C;
    while (s_copy.checkerAt(c+1, r+1) == color) {
        r++;
        c++;
    }
    if (SouthWest(c, r, N, color, s_copy) == true) {
        return true;
    }

    // EAST - WEST
    // set r, c iterators back to R, C
    // while it's still our color, go as far east as possible
    // then check if we have N in a row west from that point
    r = R;
    c = C;
    while (s_copy.checkerAt(c+1, r) == color) {
        c++;
    }
    if (West(c, r, N, color, s_copy) == true) {
        return true;
    }

    // SOUTH-EAST - NORTH-WEST
    // set r, c iterators back to R, C
    // while it's still our color, go as far south-east as possible
    // then check if we have N in a row north-west from that point
    r = R;
    c = C;
    while (s_copy.checkerAt(c+1, r-1) == color) {
        c++;
        r--;
    }
    if (NorthWest(c, r, N, color, s_copy) == true) {
        return true;
    }
    
    // we have checked every possibly direction for N in a row
    // ex: going as far north as possible then checking south
    // yields the same result as going as far south as possible and checking north
    
    // return false if we haven't found N in a row in any direction
    return false;
}

bool South(int C, int R, int N, int color, const Scaffold& s_copy) {
    // checks if we have N in a row South
    
    int r = R;
    int c = C;
    // if there isn't enough space for N in a row beneath us, don't bother looking
    if (N <= R+1) {
        for (int i = 1; i <= N; i++) {
            // for each row below us, check if the color is there
            // if it's not, break and return false later
            if (s_copy.checkerAt(c, r) != color) {
                break;
            }
            
            // if we find N in a row, return true!
            if (i == N) {
                return true;
            }
            r--;
        }
    }
    return false;
}

bool SouthWest(int C, int R, int N, int color, const Scaffold& s_copy) {
    // checks if we have N in a row South-West
    
    int r = R;
    int c = C;
    // if there isn't enough space for N in that direction, don't bother looking
    if (N <= R+1 && N <= C+1) {
        for (int i = 1; i <= N; i++) {
            // for each row/column in that direction, check if the color is there
            // if it's not, break and return false later
            if (s_copy.checkerAt(c, r) != color) {
                break;
            }
            
            // if we find N in a row, return true!
            if (i == N) {
                return true;
            }
            r--;
            c--;
        }
    }
    return false;
}

bool West(int C, int R, int N, int color, const Scaffold& s_copy) {
    // checks if we have N in a row West
    
    int r = R;
    int c = C;
    // if there isn't enough space for N to the left, don't bother looking
    if (N <= C+1) {
        for (int i = 1; i <= N; i++) {
            // for each column to the left, check if the color is there
            // if it's not, break and return false later
            if (s_copy.checkerAt(c, r) != color) {
                break;
            }
            
            // if we find N in a row, return true!
            if (i == N) {
                return true;
            }
            c--;
        }
    }
    return false;
}

bool NorthWest(int C, int R, int N, int color, const Scaffold& s_copy) {
    // checks if we have N in a row North-West
    
    int r = R;
    int c = C;
    // if there isn't enough space for N in that direction, don't bother looking
    if (N <= s_copy.levels()-R+1 && N <= C+1) {
        for (int i = 1; i <= N; i++) {
            // for each row/column in that direction, check if the color is there
            // if it's not, break and return false later
            if (s_copy.checkerAt(c, r) != color) {
                break;
            }
            
            // if we find N in a row, return true!
            if (i == N) {
                return true;
            }
            r++;
            c--;
        }
    }
    return false;
}
