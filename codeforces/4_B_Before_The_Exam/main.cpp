#include <iostream>
#include <algorithm>
// #include <string>
#include <vector>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct MinMax {
    int minTime;
    int maxTime;
};

/*
 * Find solution with backtracking. Takes too long on test 8
 */
bool find_distribution(const vector<MinMax> &vec, vector<int> &dest, const size_t i, const int remaining) {
    if (i == vec.size()) {
        if (remaining == 0) {
            return true;
        } else {
            return false;
        }
    }

    int start_value = vec[i].minTime;
    int end_value = std::min(vec[i].maxTime, remaining);

    for (int value =  start_value; value <= end_value; value++) {
        dest[i] = value;
        int new_remaining_total = remaining - value;
        if (find_distribution(vec, dest, i+1, new_remaining_total) == true) {
            return true;
        }
    }
    return false;
}

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

    return idx;
}

bool greedyDistribution(const vector<MinMax> &vec, vector<int> &result, const size_t total, int sumTime) {
    int totalMin = 0;

    for (int i = 0; i < vec.size(); i++) {
        result[i] = vec[i].minTime;
        totalMin += vec[i].minTime;
    }

    if (sumTime < totalMin) {
        return false; // Total is too small to meet all minimums
    }

    int remainingTotal = sumTime - totalMin;

    // If no remainder, we are done
    if (remainingTotal == 0) {
        return true;
    }

    // Calculate remaining capacity for each bucket
    vector<int> remainingCapacity(total);
    for (int i = 0; i < total; i++) {
        remainingCapacity[i] = vec[i].maxTime - result[i];
    }

    // Create a list of indices sorted by RemainingCapacity (smallest first)
    // Smallest capacity means this bucket is the most constrained and should be filled first
    auto sortedIndices = sort_indexes(remainingCapacity);

    // Iterate and distribute the remainder
    for (const auto i : sortedIndices) {
        auto capacity = remainingCapacity[i];

        // Amount to add is the lesser of the remaining total or the bucket's capacity
        const auto amountToAdd = std::min(remainingTotal, capacity);

        // Add to distribution
        result[i] = result[i] + amountToAdd;
        remainingTotal = remainingTotal - amountToAdd;

        // If we've used up the Total, stop
        if (remainingTotal == 0) {
            break;
        }
    }

    // Final Check: Ensure the entire Total was distributed
    if (remainingTotal > 0) {
        // This should generally not happen if the total is less than the max capacity,
        // but it means the total was too high to fit within the sum of all U_i.
        return false; // Total exceeds sum of all maximums
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int sumTime;
    cin >> sumTime;

    vector<MinMax> days(n);
    days.clear();
    int minTime;
    int maxTime;

    int ni = n;

    while (ni > 0) {
        ni-=1;
        cin >> minTime;
        cin >> maxTime;
        days.push_back(MinMax(minTime, maxTime));
    }

    vector<int> result(n);
    // Random generator approach - too slow on test 7
    // std::mt19937 generator{};
    //
    // while (true) {
    //     everyDay.clear();
    //     int total = 0;
    //     for (auto [minTime, maxTime]: days) {
    //         std::uniform_int_distribution ranged_random{ minTime, maxTime };
    //         int value = ranged_random(generator);
    //         everyDay.push_back(value);
    //         total += value;
    //     }
    //
    //     if (total == sumTime) {
    //         break;
    //     }
    // }

    // if (find_distribution(days, result, 0, sumTime)) {  // Too slow on test 8

    if (greedyDistribution(days, result, n, sumTime)) {
        cout << "YES" << endl;
        for (auto i: result) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}