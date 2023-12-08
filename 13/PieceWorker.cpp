#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PieceWorker.h"
using namespace std;

PieceWorker::PieceWorker(const string& first, const string& last, const string& ssn, double wage, int pieces)
   : Employee(first, last, ssn) {
   setWage(wage);
   setPieces(pieces);
}

void PieceWorker::setWage(double wage) {
   if (wage < 0.0)
      throw invalid_argument("Wage must be >= 0.0");
   wage_ = wage;
}

double PieceWorker::getWage() const { return wage_; }

void PieceWorker::setPieces(int pieces) {
   if (pieces < 0)
      throw invalid_argument("Pieces must be >= 0");
   pieces_ = pieces;
}

int PieceWorker::getPieces() const { return pieces_; }

double PieceWorker::earnings() const { return getWage() * getPieces(); }

string PieceWorker::toString() const {
   ostringstream output;
   output << "Piece worker employee: " << Employee::toString() << "\n"
      << "Wage: " << getWage() << "; Pieces: " << getPieces();
   return output.str();
}