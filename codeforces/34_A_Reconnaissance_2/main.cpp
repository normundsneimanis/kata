#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int height;

    while (n > 0) {
        cin >> height;
        v.push_back(height);
        n -= 1;
    }

    int min_height_diff = 1e10;
    int idx {};
    for (int i = 1; i < v.size(); i++) {
        int abs = std::abs(v[i] - v[i-1]);
        if (abs < min_height_diff) {
            min_height_diff = abs;
            idx = i-1;
        }
    }

    int abs = std::abs(v[0] - v[v.size()-1]);
    if (abs < min_height_diff) {
        cout << v.size() << " " << 1 << endl;
    } else {
        cout << idx + 1 << " " << idx + 2 << endl;
    }
    return 0;
}