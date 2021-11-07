#ifndef SUPPORT_INCLUDED
#define SUPPORT_INCLUDED

#include "provided.h"

// The following functions are used in Game and SmartPlayer to determine game outcome

bool connectN(int C, int N, int color, const Scaffold& s_copy);
    // checks if we have N in a row

bool South(int C, int R, int N, int color, const Scaffold& s_copy);
    // checks if we have N in a row South

bool SouthWest(int C, int R, int N, int color, const Scaffold& s_copy);
    // checks if we have N in a row South-West
  
bool West(int C, int R, int N, int color, const Scaffold& s_copy);
    // checks if we have N in a row West
 
bool NorthWest(int C, int R, int N, int color, const Scaffold& s_copy);
    // checks if we have N in a row North-West
 
#endif // SUPPORT_INCLUDED

