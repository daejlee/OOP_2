#include <stdlib.h>
#include "RandomAI.h"
using namespace std;

RandomAI::RandomAI(int side) : Player(side) {}

array<int, 2> RandomAI::nextTurn(array<array<int, 3>, 3> board) const {
  int row;
  int col;

  while (1) {
    row = rand() % 3;
    col = rand() % 3;
    if (board[row][col] == -1) break;
  }

	array<int, 2> next{row, col};
	return next;
}