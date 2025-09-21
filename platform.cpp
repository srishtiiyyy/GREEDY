#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Number of Platforms Required

- arr[]: arrival times of trains
- dep[]: departure times of trains
- Goal: find the minimum number of platforms required so that no train waits.
- Idea: Sort arrival and departure times separately.
        Use two pointers to simulate the platform occupation.
*/

int minPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();

    // Sort arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0; // Pointer for arrival times
    int j = 0; // Pointer for departure times
    int platform_needed = 0; // Current number of platforms needed
    int max_platform = 0;    // Maximum number of platforms needed

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            // A train has arrived before the last one departs
            platform_needed++; 
            i++;
        } else {
            // A train has departed, free a platform
            platform_needed--;
            j++;
        }

        // Update maximum platforms used
        max_platform = max(max_platform, platform_needed);
    }

    return max_platform;
}

int main() {
    // Example input: arrival and departure times of trains
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum number of platforms required: " << minPlatform(arr, dep) << endl; // Output: 3

    return 0;
}
