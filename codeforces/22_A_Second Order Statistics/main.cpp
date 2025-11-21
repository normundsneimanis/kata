#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;  // Amount of numbers in a row
    cin >> n;

    int m;

    std::vector<int> v = {};
    for (int ni = 0; ni < n; ni ++) {
        cin >> m;
        if (std::find(v.begin(), v.end(), m) == v.end())
            v.push_back(m);
    }

    if (v.size() <= 1) {
        cout << "NO" << endl;
        return 0;
    }

    std::sort(v.begin(), v.end());

    cout << v[1] << endl;
    return 0;
}