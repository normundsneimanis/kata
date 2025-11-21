#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

/**
 * @brief Checks if a subset of the given array sums up to the target.
 *
 * This uses the Tabulation (Bottom-Up) Dynamic Programming approach.
 * Complexity: O(N * Target) time, O(N * Target) space (or O(Target) with optimization).
 *
 * @param nums The array of positive integers.
 * @param target The specific sum to find.
 * @return true if a subset exists, false otherwise.
 */
bool canFindSubsetSum(const std::vector<int>& nums, int target) {
    // Edge case: If the target is 0, an empty subset always works.
    if (target == 0) {
        return true;
    }

    // Since all numbers are positive, we can't exceed the target.
    // Also, if the target is negative, it's impossible to reach.
    if (target < 0) {
        return false;
    }

    // N is the number of elements in the array.
    int N = nums.size();

    // 1. Define the State (DP Table)
    // DP[i][s]: Is it possible to achieve sum 's' using a subset of the first 'i' numbers?
    // Rows: N + 1 (for 0 to N items)
    // Columns: target + 1 (for 0 to target sum)
    std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(target + 1));

    // 3. Identify the Base Case(s)
    // Base Case 1: dp[i][0] = true (Sum 0 is always achievable with an empty set)
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = true;
    }
    // Base Case 2: dp[0][s] = false for s > 0 (Non-zero sum is impossible with 0 items)
    // This is handled automatically since the vector<bool> is default-initialized to false.

    // 4. Implement Tabulation (The Loops)
    // Iterate through items (i) and sums (s)
    for (int i = 1; i <= N; ++i) {
        // nums[i-1] is the current element we are considering (A[i])
        int current_num = nums[i - 1];

        for (int s = 1; s <= target; ++s) {

            // Recurrence: Choice A (Exclude current_num)
            // Can we achieve sum 's' without current_num?
            bool exclude = dp[i - 1][s];

            // Recurrence: Choice B (Include current_num)
            bool include = false;
            if (s >= current_num) {
                // Can we achieve the remaining sum (s - current_num) with previous items?
                include = dp[i - 1][s - current_num];
            }

            // 2. Formulate the Recurrence Relation (The Transition)
            // DP[i][s] is true if either choice is true.
            dp[i][s] = exclude || include;
        }
    }

    cout << "dp array: \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < target; j++) {
            printf("dp[%d][%d]: %d ", i, j, static_cast<int>(dp[i][j]));
        }
        cout << '\n';
    }

    {
        int i = N;
        int j = target;
        while (i != 0 && j != 0) {
            if (dp[i-1][j] == true) {
                i -= 1;
            } else {
                printf("%d (%d) was used ", i, nums[i] - 1);
                i = i - 1;
                j = j - nums[i];
            }
        }
        cout << '\n';
    }

    // The final answer is in the bottom-right corner of the DP table.
    return dp[N][target];
}

// Space-Optimized Subset Sum (O(Target) space)
bool canFindSubsetSumOptimized(const std::vector<int>& nums, int target) {
    if (target < 0) return false;

    // 1. Define the State (1D DP Array)
    // dp[s]: Is it possible to achieve sum 's' using elements considered so far?
    std::vector<bool> dp(target + 1, false);

    // 3. Identify the Base Case
    dp[0] = true; // Sum 0 is always achievable

    // 4. Implement Tabulation (Optimized)
    // Iterate through items (A[i])
    for (int current_num : nums) {
        // Iterate sums (s) DOWNWARDS
        // Only sums greater than or equal to the current number are relevant
        for (int s = target; s >= current_num; --s) {

            // 2. Formulate the Recurrence Relation (Implicit Transition)
            // The new dp[s] (after considering current_num) is true if:
            // 1. It was already true (dp[s] before update, i.e., Choice A: Exclude)
            // OR
            // 2. We can achieve the sum s - current_num (dp[s - current_num])
            //    and then add the current_num (Choice B: Include)
            dp[s] = dp[s] || dp[s - current_num];
        }
    }

    return dp[target];
}

int main() {
    // // Find which two indexes of an array amount to target number
    // vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // unordered_map<int, int> map = {};
    // const int target = 10;
    //
    // // Generate amount missing in O(N) time and O(N) space;
    // for (int i = 0; i < data.size(); i++) {
    //     const int complement  = target - data[i];
    //     if (auto it = map.find(data[i]); it != map.end()) {
    //         printf("Array: ");
    //         for (int j : data) {
    //             cout << j << " ";
    //         }
    //         cout << '\n';
    //         printf("Elements amounting to %d are %d (%d) and %d (%d)", target, data[i], i, data[it->second], it->second);
    //         break;
    //     }
    //     map.insert({complement, i});
    // }


    // // Find which 3 indexes of an array amount to target number, by using smallest amount of elements
    // vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // unordered_map<int, int> map = {};
    // const int target = 15;
    //
    // // Generate amount missing in O(N) time and O(N) space;
    // for (int i = 0; i < data.size(); i++) {
    //     const int complement  = target - data[i];
    //     if (auto it = map.find(data[i]); it != map.end()) {
    //         printf("Array: ");
    //         for (int j : data) {
    //             cout << j << " ";
    //         }
    //         cout << '\n';
    //         printf("Elements amounting to %d are %d (%d) and %d (%d)", target, data[i], i, data[it->second], it->second);
    //         break;
    //     }
    //     map.insert({complement, i});
    // }

    std::vector<int> arr1 = {3, 34, 4, 12, 5, 2};
    int target1 = 9;

    std::vector<int> arr2 = {1, 2, 3};
    int target2 = 7;

    std::vector<int> arr3 = {10, 20, 30};
    int target3 = 0;

    std::vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int target4 = 15;

    // Test Case 1: Subset {3, 4, 2} sums to 9 (True)
    bool result1 = canFindSubsetSum(arr1, target1);
    std::cout << "Array: {3, 34, 4, 12, 5, 2}, Target: 9 -> " << (result1 ? "True" : "False") << std::endl;

    // Test Case 2: No subset sums to 7 (False)
    bool result2 = canFindSubsetSum(arr2, target2);
    std::cout << "Array: {1, 2, 3}, Target: 7 -> " << (result2 ? "True" : "False") << std::endl;

    // Test Case 3: Target 0 (True)
    bool result3 = canFindSubsetSum(arr3, target3);
    std::cout << "Array: {10, 20, 30}, Target: 0 -> " << (result3 ? "True" : "False") << std::endl;

    // Test Case 3: Target 0 (True)
    bool result4 = canFindSubsetSum(arr4, target4);
    std::cout << "Array:  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, Target: 15 -> " << (result4 ? "True" : "False") << std::endl;

    return 0;
}