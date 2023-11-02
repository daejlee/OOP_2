#include <iostream>
using namespace std;

void recursiveBackward(const int* ptr, size_t size){
    if (size)
        recursiveBackward(ptr + 1, size - 1);
    else
        return ;
    cout << *ptr << " ";
}

int main(){
    array<int, 5> arr = {10, 20, 30, 40, 50};
    const int*  b = &arr[0];
    cout << "\n Test of the recursiveBackward function\n";
    recursiveBackward(b, 5);
}