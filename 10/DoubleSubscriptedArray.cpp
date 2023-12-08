#include <iomanip>
#include <stdexcept>
#include "DoubleSubscriptedArray.h"
using namespace std;

DoubleSubscriptedArray::DoubleSubscriptedArray(int columnSize, int rowSize) : ptr(nullptr) {
    //no column size?
    if (rowSize > 0) _rowSize = rowSize;
    else throw invalid_argument("Row size must be > 0");
    if (columnSize >= 0) _columnSize = columnSize;
    else throw invalid_argument("Column size must be >= 0");
    int matrixSize = rowSize * columnSize;
    ptr = new int[matrixSize];
    for (size_t loop = 0; loop < matrixSize; ++loop) ptr[loop] = 0;
}

DoubleSubscriptedArray::~DoubleSubscriptedArray(){ delete []ptr; }

size_t  DoubleSubscriptedArray::getRowSize() const { return _rowSize; }

size_t  DoubleSubscriptedArray::getColumnSize() const { return _columnSize; }

bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &rhs) const {
    if ((_rowSize != rhs.getRowSize()) || (_columnSize != rhs.getColumnSize())) return false;
    size_t matrixSize = _rowSize * _columnSize;
    for (size_t loop = 0; loop < matrixSize; ++loop) if (ptr[loop] != rhs.ptr[loop]) return false;
    return true;
}

int& DoubleSubscriptedArray::operator()(size_t rowSub, size_t colSub) const {
    if ((rowSub < 0 || rowSub >= _rowSize) || colSub < 0 || colSub >= _columnSize)
        throw invalid_argument("One or Both subscripts out of range");
    return ptr[(rowSub * _columnSize) + colSub];
}

istream &operator>>(istream& input, DoubleSubscriptedArray& a){
    size_t matrixSize = a.getRowSize() * a.getColumnSize();
    for (size_t loop = 0; loop < matrixSize; ++loop) input >> a.ptr[loop];
    return input;
}

ostream &operator<<(ostream& output, DoubleSubscriptedArray& a){
    size_t matrixSize = a.getRowSize() * a.getColumnSize();
    for (size_t i = 0; i < a.getColumnSize(); ++i) {
        for (size_t k = 0; k < a.getRowSize(); ++k)
            output << a.ptr[i * a.getRowSize() + k] << " ";
        output << "\n";
    }
    return output;
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& arg) : ptr(nullptr) {
    _rowSize = arg.getRowSize();
    _columnSize = arg.getColumnSize();
    size_t matrixSize = arg.getRowSize() * arg.getColumnSize();
    ptr = new int[matrixSize];
    for (size_t loop = 0; loop < matrixSize; ++loop) ptr[loop] = arg.ptr[loop]; //deep copy
}

bool    DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& rhs) const{
    if ((_rowSize == rhs.getRowSize()) && (_columnSize == rhs.getColumnSize())) return false;
    size_t matrixSize = _rowSize * _columnSize;
    for (size_t loop = 0; loop < matrixSize; ++loop) if (ptr[loop] == rhs.ptr[loop]) return false;
    return true;
}

DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& arg){
    _rowSize = arg.getRowSize();
    _columnSize = arg.getColumnSize();
    size_t matrixSize = arg.getRowSize() * arg.getColumnSize();
    for (size_t loop = 0; loop < matrixSize; ++loop) ptr[loop] = arg.ptr[loop]; //shallow copy
    return *this;
}