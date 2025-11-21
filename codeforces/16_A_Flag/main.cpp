#include <iostream>

using std::cin;
using std::cout;

int main() {
    int n;  // Amount of rows
    cin >> n;
    int m; // Amount of colors
    cin >> m;

    char prev_color = -1;
    bool is_flag = true;
    for (int ni = 0; ni < n; ni ++) {
        char chars[m];
        for (int mi = 0; mi < m; mi++) {
            cin >> chars[mi];
            if (mi > 0 && chars[mi-1] != chars[mi]) {
                is_flag = false;
            }
        }
        if (ni > -1 && chars[0] == prev_color) {
            is_flag = false;
        }
        prev_color = chars[0];
    }
    cout << (is_flag ? "YES" : "NO") << '\n';

    return 0;
}