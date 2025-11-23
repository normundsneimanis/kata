#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

int main() {
    int n_tests;
    cin >> n_tests;
    int n_expansions;
    int p_x;
    int p_y;
    char expansion;

    while (n_tests > 0) {
        cin >> n_expansions;
        cin >> p_x;
        cin >> p_y;
        vector<vector<bool>> v(p_x, vector<bool>(p_x, false));
        v[0][0] = true;
        int current_border_x = 0;
        int current_border_x2 = 0;
        while (n_expansions > 0) {
            cin >> expansion;
            n_expansions -= 1;
            if (expansion == '4') {
                current_border_x += 1;
            } else if (expansion == '8') {
                current_border_x += 1;
                current_border_x2 += 1;
            }
        }

        n_tests -= 1;

        // if (current_border_x >= std::abs(p_x) && current_border_x2 >= std::abs(p_y)) {
        if ((c.x >= a.x && c.x <= b.x) &&
           (1LL * (c.y - a.y) * (b.x - a.x) <= 1LL * (b.y - a.y) * (c.x - a.x)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}