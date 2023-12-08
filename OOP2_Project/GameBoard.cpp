#include <iomanip> 
#include <stdexcept>
#include <iostream> 
#include "GameBoard.h"
using namespace std;

int GameBoard::checkRowCol() const {
  int xCount = 0;
  int oCount = 0;

  // Check rows
  for (int r{ 0 }; r < 3; ++r) {
      for (int c{ 0 }; c < 3; ++c) {
          if (board[r][c] == 0) ++xCount;
          else if (board[r][c] == 1) ++oCount;
      }
      if (xCount == 3) return WIN;
      else if (oCount == 3) return WIN;
      else {
          xCount = 0;
          oCount = 0;
      }
  }
  // Check columns
  for (int c{ 0 }; c < 3; ++c) {
      for (int r{ 0 }; r < 3; ++r) {
          if (board[r][c] == 0) ++xCount;
          else if (board[r][c] == 1) ++oCount;
      }
      if (xCount == 3) return WIN;
      else if (oCount == 3) return WIN;
      else {
          xCount = 0;
          oCount = 0;
      }
  }
  return -1;
}

int GameBoard::checkDiag() const {
  int xCount = 0;
  int oCount = 0;

  for (int i{ 0 }; i < 3; ++i) {
      if (board[i][i] == 0) ++xCount;
      else if (board[i][i] == 1) ++oCount;
  }
  if (xCount == 3) return WIN;
  else if (oCount == 3) return WIN;
  else {
      xCount = 0;
      oCount = 0;
  }
  for (int i{ 0 }; i < 3; ++i) {
      if (board[i][2 - i] == 0) ++xCount;
      else if (board[i][2 - i] == 1) ++oCount;
  }
  if (xCount == 3) return WIN;
  else if (oCount == 3) return WIN;
  else {
      xCount = 0;
      oCount = 0;
  }
  return -1;
}

GameBoard::GameBoard() {
  for (int j{ 0 }; j < 3; ++j) {
      for (int k{ 0 }; k < 3; ++k) {
          board[j][k] = -1;
      }
  }

  int playerType;
  cout << "Welcome to the TicTacToe game!\n" 
      << "0 - Human Player\n" << "1 - Random AI\n";

  while (1) {
    cout << "Choose Player 1 (symbol X): ";
    playerType = getIntInput();
    if (playerType != 0 && playerType != 1){
      cout << "Input number must be 0 or 1!" << endl;
      continue;
    }
    if (playerType == 0){
      static HumanPlayer player1(playerType);
      p1 = &player1;
    }
    else {
      static RandomAI player1(playerType);
      p1 = &player1;
    }
    cout << "Choose Player 2 (symbol O): ";
    playerType = getIntInput();
    if (playerType != 0 && playerType != 1){
      cout << "Input number must be 0 or 1!" << endl;
      continue;
    }
    if (playerType == 0){
      static HumanPlayer player2(playerType);
      p2 = &player2;
    }
    else {
      static RandomAI player2(playerType);
      p2 = &player2;
    }
    break;
  }
}

void GameBoard::printBoard() const {
    // Function for printing the current board state.
    // Please do not edit this function.
    cout << "\n   0    1    2\n\n";

    for (int r{ 0 }; r < 3; ++r) {
        cout << r;

        for (int c = 0; c < 3; ++c) {
            char symbol;
            if (board[r][c] == -1)
                symbol = ' ';
            else if (board[r][c] == 0)
                symbol = 'X';
            else if (board[r][c] == 1)
                symbol = 'O';
            else
                throw "Invalid value in game board!";

            cout << setw(3) << symbol;

            if (c != 2) {
                cout << " |";
            }
        }

        if (r != 2) {
            cout << "\n ____|____|____\n     |    |    \n";
        }
    }

    cout << "\n\n";
}

GameBoard::Status GameBoard::gameStatus() const {
  if (checkRowCol() == WIN) return WIN;
  else if (checkDiag() == WIN) return WIN;
  for (int r{ 0 }; r < 3; ++r)
      for (int c{ 0 }; c < 3; ++c)
        if (board[r][c] == -1) return CONTINUE;
  return DRAW;
}

void GameBoard::run() {
  array<int, 2> nextMove;
  Status currStatus;    
  printBoard();

  while (true) {        
    nextMove = p1->nextTurn(board);
    board[nextMove[0]][nextMove[1]] = 0;
    printBoard();
    currStatus = gameStatus();
    if (currStatus == WIN) {
      cout << "Player 1 wins!" << endl;
      break;
    }
    else if (currStatus == DRAW) {
      cout << "Draw!" << endl;
      break;
    }
    nextMove = p2->nextTurn(board);
    board[nextMove[0]][nextMove[1]] = 1;
    printBoard();
    currStatus = gameStatus();
    if (currStatus == WIN) {
      cout << "Player 2 wins!" << endl;
      break;
    }
    else if (currStatus == DRAW) {
      cout << "Draw!" << endl;
      break;
    }
  }
}
