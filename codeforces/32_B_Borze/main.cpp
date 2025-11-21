#include <iostream>

using std::cin;
using std::cout;

int main() {
    char n;  // Amount of rows
    char prev = 0;

    while (cin.peek() != '\n') {
        cin >> n;
        // cout << "Red [" << n << "]" << std::endl;
        if (cin.eof()) {
            break;
        }
        if (n == '.' && prev == 0) {
            cout << 0;
        } else {
            if (prev == '-' && n == '-') {
                cout << 2;
                prev = 0;
            } else if (prev == '-' && n == '.') {
                cout << 1;
                prev = 0;
            } else {
                prev = n;
            }
        }
    }

    return 0;
}