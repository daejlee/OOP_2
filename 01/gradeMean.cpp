#include <iostream>
using namespace std;

int main() {
    int          raw_score;
    unsigned int a_score = 0;
    unsigned int b_score = 0;
    unsigned int c_score = 0;
    unsigned int d_score = 0;
    unsigned int f_score = 0;
    double       sum = 0;
    unsigned int i = 0;

    while (i < 10) {
        cout << "Enter score (<=100 and >=0): ";
        cin >> raw_score;
        if (raw_score > 100 | raw_score < 0) {
            cout << "Please enter valid score!\n";
            continue;
        }
        else if (raw_score >= 90)
            a_score += 1;
        else if (raw_score >= 80)
            b_score += 1;
        else if (raw_score >= 70)
            c_score += 1;
        else if (raw_score >= 60)
            d_score += 1;
        else
            f_score += 1;
        sum += static_cast<double>(raw_score);
        i++;
    }
    cout << "A: " << a_score;
    cout << "\nB: " << b_score;
    cout << "\nC: " << c_score;
    cout << "\nD: " << d_score;
    cout << "\nF: " << f_score;
    cout << "\nAvg: " << static_cast<int>(sum / 10);
}