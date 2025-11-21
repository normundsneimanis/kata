#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string line1;
    std::getline(cin, line1);
    string line2;
    std::getline(cin, line2);

    if (line1.length() != line2.length()) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < line1.length() ; i++) {
            if (line1[i] != line2[line1.length()-(i+1)]) {
                cout << "NO" << endl;
                std::exit(0);
            }
        }
        cout << "YES" << endl;

    }

    return 0;
}