#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;

template<typename T>
void printM(const vector<vector<T>> &matrix, int n) {
    cout << "printM()" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

template<typename T>
void printMN(const vector<vector<vector<T>>> &matrix, int n) {
    cout << "printM()" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                cout << matrix[i][j][k] << ' ';
            }
            cout << "\n--\n";
        }
        cout << '\n';
    }
    cout << endl;
}

struct PathData {
    int prev_i;
    int prev_j;
    int prev_r;
};

int main() {
    int n;
    cin >> n;

    vector matrix(n, vector<int>(n));
    vector dp(n, vector(n, vector<long long>(10)));
    vector path(n, vector(n, vector<PathData>(10)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            for (int r = 0; r < 10; r++) {
                dp[i][j][r] = LLONG_MAX;
                path[i][j][r] = PathData { -1, -1, -1 };
            }
        }
    }

    dp[0][0][matrix[0][0] % 10] = matrix[0][0];

    // row
    for (int j = 1; j < n; j++) {
        for (int r_prev = 0; r_prev < 10; r_prev++) {
            if (dp[0][j-1][r_prev] != LLONG_MAX) {
                long long prod = matrix[0][j] * dp[0][j-1][r_prev];
                const long long r_new = prod % 10;
                dp[0][j][r_new] = std::min(dp[0][j][r_new], prod);
            }
        }
    }

    // column
    for (int i = 1; i < n; i++) {
        for (int r_prev = 0; r_prev < 10; r_prev++) {
            if (dp[i-1][0][r_prev] != LLONG_MAX) {
                long long prod = matrix[i][0] * dp[i-1][0][r_prev];
                const long long r_new = prod % 10;
                dp[i][0][r_new] = std::min(dp[i][0][r_new], prod);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int r_prev = 0; r_prev < 10; r_prev++) {
                // --- A. Coming from UP (i-1, j) ---
                if (dp[i-1][j][r_prev] != LLONG_MAX) {
                    long long prod_down = matrix[i][j] * dp[i-1][j][r_prev];
                    long long r_new = prod_down % 10;
                    dp[i][j][r_new] = std::min(dp[i][j][r_new], prod_down);
                    path[i][j][r_new] = PathData {i - 1, j, r_prev};
                }

                // --- B. Coming from LEFT (i, j-1) ---
                if (dp[i][j-1][r_prev] != LLONG_MAX) {
                    long long prod_right = matrix[i][j] * dp[i][j-1][r_prev];
                    const long long r_new = prod_right % 10;
                    dp[i][j][r_new] = std::min(dp[i][j][r_new], prod_right);
                    path[i][j][r_new] = PathData {i, j - 1, r_prev};
                }
            }
        }
    }

    printM(matrix, n);
    printMN(dp, n);

    string directions {};
    int current_i = n - 1;
    int current_j = n - 1;
    int current_r = 0;

    // Backtrack until the starting cell (0, 0) is reached
    while (current_i > 0 || current_j > 0) {
        // Retrieve the parent state from the Parent table P
        auto prev_i = path[current_i][current_j][current_r].prev_i;
        auto prev_j = path[current_i][current_j][current_r].prev_j;
        auto prev_r = path[current_i][current_j][current_r].prev_r;

        // Determine the move taken to get to (current_i, current_j)
        if (prev_i < current_i) {
            // Moved Down from (i-1, j)
            directions += 'D';
        }
        else if (prev_j < current_j) {
            // Moved Right from (i, j-1)
            directions += 'R';
        }

        // Move to the parent state for the next iteration
        current_i = prev_i;
        current_j = prev_j;
        current_r = prev_r;
    }

    cout << dp[n-1][n-1][0] << endl;
    std::reverse(directions.begin(), directions.end());
    cout << directions << endl;

    return 0;
}