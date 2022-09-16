
#ifndef _GAME_H
#define _GAME_H

class game {
public:
  game(int);
  int guess(unsigned int);

protected:
  unsigned int number;
};

#endif
