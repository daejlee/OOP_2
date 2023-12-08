#include <iostream>
#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(int side) : Player(side) {}

array<int, 2> HumanPlayer::nextTurn(array<array<int, 3>, 3> board) const {
  int row;
  int col;

  // Get input from user
  while (1) {
    cout << "Enter the row number of your next move: ";
    row = getIntInput();
    cout << "Enter the column number of your next move: ";
    col = getIntInput();
    if (row < 0 || row > 2 || col < 0 || col > 2) cout << "Please input value between 0 and 2!" << endl;
    else if (board[row][col] != -1) cout << "That point is already occupied!" << endl;
    else break;
  }

  array<int, 2> next{row, col};
	return next;
}