#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

class City;

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
};


int decodeDirection(char dir);

#endif
