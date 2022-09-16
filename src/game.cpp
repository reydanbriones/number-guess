
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

game::game (int diff) {
  srand(time(NULL));
  number = rand() % diff + 1;
}

int game::guess (unsigned int guess) {
  return number == guess;
}
