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

struct Data {
    long int points;
    int num;
};

struct Data2 {
    string name;
    long int points;
    int num;
};

int main() {
    int n;
    cin >> n;

    int ni = 0;
    string input_name = {};
    long int points = {};
    unordered_map<string, Data> registered {};
    vector<Data2> timeline {};
    std::string name_first;
    while (ni < n) {
        cin >> input_name;
        cin >> points;
        if (input_name.empty()) {
            continue;
        }
        ni += 1;
        if (auto it = registered.find(input_name); it != registered.end()) {
            it->second.points = it->second.points + points;
            timeline.push_back(Data2 { input_name, it->second.points, ni});
            it->second.num = ni;
        } else {
            registered.insert({input_name, Data {points, ni}});
            timeline.push_back(Data2 { input_name, points, ni});
        }
    }

    points = -1;
    name_first.clear();
    for (const auto& [key, data] : registered) {
        if (data.points > points) {
            points = data.points;
        }
    }

    for (const auto& data2 : timeline) {
        if (auto it = registered.find(data2.name); it != registered.end()) {
            if (it->second.points < 0) {
                // cout << "Skipping " << it->first << " because of negative points: " << it->second.points << '\n';
                continue;
            }
            if (data2.points >= points && it->second.points == points) {
                // cout << "Winner is " << data2.name << " with " << data2.points << '\n';
                name_first = data2.name;
                break;
            }
        }
    }

    // if (n == 50) {
        // for (const auto& [name, value] : registered) {
        //     cout << name << " " << value.points << " " << value.num << "|";
        // }
        // cout << '\n' << name_first << " " << points << endl;
    // } else {
    cout << name_first << endl;
    // }
    return 0;
}