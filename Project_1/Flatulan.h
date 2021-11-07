#ifndef Flatulan_h
#define Flatulan_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

class City;

class Flatulan
{
  public:
        // Constructor
    Flatulan(City* cp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    bool haveIBeenConverted() const;

        // Mutators
    void move();

  private:
    City* m_city;
    int   m_row;
    int   m_col;
};

#endif
