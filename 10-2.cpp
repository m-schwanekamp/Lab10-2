//Lab10-2
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
bool isCardValid (int digits[], int size);

int main() {
    int digits[16], i;

    while (true) {
        long long digits;
        const int size = 16;
        int value[size];

        cout << "Enter 16-digit credit card # or Q to quit: ";
        cin >> digits;

        if (cin.fail()) break;

        for (i = size - 1; i > 0; i--) {
            int t = digits % 10;
            value[i] = t;
            digits /= 10;
        }
        value[0] = digits;

        if(isCardValid(value, size)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is invalid." << endl;
        }
    }
}

bool isCardValid(int digits[], int size) {
    int even = 0;
    int odd = 0;
    int t = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            t = digits[i] * 2;
            even += t % 10;
            even += t / 10;
        }
        else {
            odd += digits[i];
        }
    }

    if ((even + odd) % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}
