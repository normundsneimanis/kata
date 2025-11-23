#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

int main() {
    int num_tests;
    cin >> num_tests;

    const vector legs = {2, 4};

    int ni = 0;
    int number_of_legs;
    while (ni < num_tests) {
        ni++;
        cin >> number_of_legs;
        if (number_of_legs == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> dp(number_of_legs + 1, 0);
        dp[0] = 1;

        cout << "dp[i] += dp[i - leg]:" << endl;
        for (const int leg : legs) {
            for (int i = leg; i <= number_of_legs; ++i) {
                printf("dp[%d] += dp[%d - %d] [%d]: %d;\n", i, i, leg, (i - leg), dp[i - leg]);
                dp[i] += dp[i - leg];
            }
        }

        cout << dp[number_of_legs] << endl;
    }
    return 0;
}