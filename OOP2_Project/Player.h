#ifndef PLAYER_H
# define PLAYER_H
# include <array>
# include <iostream>

class Player {
public:
	Player(int);
	virtual std::array<int, 2> nextTurn(std::array<std::array<int, 3>, 3>) const = 0;
protected:
	int side_;    // 0 for Player X and 1 for Player O
};

#endif
