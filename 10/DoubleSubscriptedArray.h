#ifndef OOP_2_DOUBLESUBSCRIPTEDARRAY_H
#define OOP_2_DOUBLESUBSCRIPTEDARRAY_H
#include <iostream>

class DoubleSubscriptedArray{
    friend std::istream &operator>>(std::istream&, DoubleSubscriptedArray&);
    friend std::ostream &operator<<(std::ostream&, DoubleSubscriptedArray&);
public:
    explicit DoubleSubscriptedArray(int = 3, int = 3);
    ~DoubleSubscriptedArray();
    size_t  getRowSize() const;
    size_t  getColumnSize() const;
    bool    operator==(const DoubleSubscriptedArray&) const;
//    int     operator()(size_t, size_t) const;

    DoubleSubscriptedArray(const DoubleSubscriptedArray&);
    bool    operator!=(const DoubleSubscriptedArray&) const;
    DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray&);
    int&     operator()(size_t, size_t) const;

private:
    size_t  _rowSize;
    size_t  _columnSize;
    int*    ptr;
};

#endif //OOP_2_DOUBLESUBSCRIPTEDARRAY_H
