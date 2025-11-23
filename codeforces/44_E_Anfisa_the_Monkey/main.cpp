#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    int k, a, b;
    cin >> k;
    cin >> a;
    cin >> b;

    string input;
    cin >> input;

    int size = input.size();
    if (size < a*k || size > b*k) {
        cout << "No solution" << endl;
        return 0;
    }

    int i0 = 0;
    int i1 = static_cast<int>(std::round(size/k));
    int lines_printed = 0;
    do {
        cout << input.substr(i0, i1 - i0) << '\n';
        lines_printed += 1;
        i0 = i1;
        if (size - i0 > 0)
            i1 += static_cast<int>(std::round((size - i0)/(k-lines_printed)));
    } while (lines_printed < k);

    return 0;
}
