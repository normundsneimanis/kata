#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::string_view;
using std::find;
using std::size_t;

int main() {
    string command;
    int num_bytes_sent = 0;
    std::vector<string> users {};
    while (cin.peek() != '\n' && !cin.eof()) {
        getline(cin, command);
        if (command.starts_with('+')) {
            users.push_back(command.substr(1, command.length()));
        } else if (command.starts_with('-')) {
            std::erase(users, command.substr(1, command.length()));
        } else {
            size_t delim_start = command.find(':');
            string message = command.substr(delim_start + 1, command.length() - delim_start);
            num_bytes_sent += message.length() * users.size();
        }
    }
    cout << num_bytes_sent << endl;
    return 0;
}