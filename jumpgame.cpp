/*
Question: Jump Game (Leetcode 55)

You are given an integer array `nums`. Each element `nums[i]` represents your maximum 
jump length from that position.  

- Starting from index 0, return true if you can reach the last index, otherwise false.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation:
Index 0 → jump 1 step to index 1, then jump 3 steps to index 4 (last index).

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation:
You will always stop at index 3 because nums[3] = 0, cannot move further.

---

Approach (Greedy):
- Maintain `maxIndex`, the farthest index you can reach so far.
- Traverse the array:
   - If current index `i` is beyond `maxIndex`, it means we cannot reach this position → return false.
   - Otherwise, update `maxIndex = max(maxIndex, i + nums[i])`.
- If we finish the loop, it means we could always move forward → return true.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0; // farthest reachable index so far

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) {
                // if current position is unreachable
                return false;
            }
            // update farthest reachable index
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution solution;
    bool ans = solution.canJump(nums);

    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}
