#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main() {
    vector<string> lines;
    string current_line;
    int max_len = 0;
    while (!cin.eof()) {
        getline(cin, current_line);
        if (current_line.size() > max_len) {
            max_len = static_cast<int>(current_line.size());
        }
        lines.push_back(current_line);
    }

    cout << string(max_len+2, '*') << '\n';
    int choose_right = true;
    for (int i = 0; i < lines.size(); i++) {
        if (i == lines.size() - 1 && lines[i].empty()) {
            break;
        }
        int si = static_cast<int>(lines[i].size());
        int num_pre = static_cast<int>((max_len - si) / 2);
        int num_post = static_cast<int>((max_len - si) / 2);
        if (max_len % 2 == 0 && si % 2 != 0) {
            if (choose_right) {
                num_post += 1;
            } else {
                num_pre += 1;
            }
            choose_right = !choose_right;
        } else if (max_len % 2 != 0 && si % 2 == 0) {
            if (choose_right) {
                num_post += 1;
            } else {
                num_pre += 1;
            }
            choose_right = !choose_right;
        }
        cout << "*" << string(num_pre, ' ') << lines[i] << string(num_post, ' ') << "*" << '\n';
    }
    cout << string(max_len+2, '*') << '\n';

    return 0;
}