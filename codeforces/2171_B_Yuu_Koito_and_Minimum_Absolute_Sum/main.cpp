#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

int main() {
    int num_tests;
    cin >> num_tests;

    int ni = 0;
    int num_objs;
    int num;
    vector<int> numbers;
    while (ni < num_tests) {
        cin >> num_objs;
        while (num_objs > 0) {
            cin >> num;
            numbers.push_back(num);
        }
    }
    return 0;
}