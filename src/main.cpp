
#include <iostream>
#include "game.h"

using namespace std;

const unsigned int diffs[3][2] = {
  {5, 3},
  {10, 5},
  {100, 10}
};

int choose_diff (void);

int main () {
  srand(time(NULL));

  int diff = choose_diff();
  while (diff != -1) {
    const unsigned int number = diffs[diff][0];
    const unsigned int tries = diffs[diff][1];
    unsigned int guess;
    game g_game(number);

    for (unsigned int i = 0; i < tries; i++) {
      cout << "Guess number from 1-" << number << " (" << (tries - i) << " tries left): ";
      cin >> guess;
      if (g_game.guess(guess)) {
        cout << "Correct! You won" << endl << endl;
        break;
      }
    }

    cout << "Starting new game..." << endl;
    diff = choose_diff();
  };

  return 0;
}

int choose_diff (void) {
  int in_diff;

  cout << "Choose a difficulty:" << endl;
  cout << "[1] Easy (1-5, 3 tries)" << endl;
  cout << "[2] Medium (1-10, 5 tries)" << endl;
  cout << "[3] Impossible (1-100, 10 tries)" << endl;
  cout << "[0] Exit" << endl;
  cin >> in_diff;

  if (in_diff > 3 || in_diff < 0) {
    cout << "Invalid input" << endl;
    in_diff = -1;
  }

  return in_diff - 1;
}
