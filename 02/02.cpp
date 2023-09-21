#include <iostream>
using namespace std;

void    print_char_iter(int iter, char c){
    if (!iter)
        return;
    for (int i = 0; i < iter; i++)
        cout << c;
}

int main(){
    int length = 0;
    int blank = 0;
    bool revers_flag;
    cout << "input the length: ";
    while (cin >> length){
        revers_flag = false;
        if (!(length % 2) || length <= 4 || length >= 22) {
            cout << "Please input valid length!\n";
            cout << "\ninput the length: ";
            continue;
        }
        blank = 0;
        print_char_iter(length, '#');
        for (int i = 0; i < length - 2; i++){
            cout << "\n#";
            print_char_iter(blank, ' ');
            print_char_iter(length - blank * 2 - 2, '*');
            print_char_iter(blank, ' ');
            if (length - blank * 2 - 2 == 1)
                revers_flag = true;
            if (!revers_flag)
                blank += 1;
            else
                blank -= 1;
            cout << "#";
        }
        cout << "\n";
        print_char_iter(length, '#');
        cout << "\ninput the length: ";
    }
}