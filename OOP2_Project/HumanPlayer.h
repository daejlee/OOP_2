#ifndef HUMANPLAYER_H
# define HUMANPLAYER_H
# include "Player.h"

// Parse integer input from user - util function
inline int getIntInput () {
  int input;
  while (1) {
    std::cin >> input;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please input an integer!" << std::endl << "Try again: ";
      continue;
    }
    break;
  }
  return input;
}

class HumanPlayer : public Player{
public:
	HumanPlayer(int);
	virtual std::array<int, 2> nextTurn(std::array<std::array<int, 3>, 3>) const override;
};

#endif
