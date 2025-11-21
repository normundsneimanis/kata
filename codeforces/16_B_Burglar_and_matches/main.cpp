#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

int main() {
    int num_matchboxes_to_take;
    cin >> num_matchboxes_to_take;
    int num_containers;
    cin >> num_containers;

    int ni = 0;
    int num_matchboxes_i;
    int num_matches_i;

    unordered_map<int, int> num_matches;
    while (ni < num_containers) {
        ni++;
        cin >> num_matchboxes_i;
        cin >> num_matches_i;
        if (auto it = num_matches.find(num_matches_i); it != num_matches.end()) {
            it->second += num_matchboxes_i;
        } else {
            num_matches.insert({num_matches_i, num_matchboxes_i});
        }
    }

    vector<int> sizes (num_matches.size());
    for(auto kv : num_matches) {
        sizes.push_back(kv.first);
    }
    std::sort(sizes.begin(), sizes.end());
    std::reverse(sizes.begin(), sizes.end());

    int total = 0;
    int taken_boxes = 0;
    for (int i = 0; i < std::min(num_matchboxes_to_take, static_cast<int>(num_matches.size())); i++) {
        auto _num_boxes = num_matches.at(sizes[i]);
        if (_num_boxes + taken_boxes >= num_matchboxes_to_take) {
            total += (num_matchboxes_to_take - taken_boxes) * sizes[i];
            break;
        } else {
            total += sizes[i] * _num_boxes;
            taken_boxes += _num_boxes;
        }
    }

    cout << total << endl;

    return 0;
}
