#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::unordered_map;

bool find(vector<string> &vec, std::string_view what) {
    return std::find(vec.begin(), vec.end(), what) != vec.end();
}

int main() {
    int n;
    cin >> n;

    int ni = n;
    string input_name = {};
    unordered_map<string, int> registered = {};
    while (ni > 0) {
        getline(cin, input_name);
        if (input_name.empty()) {
            continue;
        }
        ni -= 1;
        auto it = registered.find(input_name);
        if (it != registered.end()) {
            it->second = it->second + 1;
            cout << it->first + std::to_string(it->second) << '\n';
        } else {
            registered.insert(std::make_pair(input_name, 0));
            cout << "OK" << '\n';
        }
    }
    cout << endl;
    return 0;
}