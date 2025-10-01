#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Broken Calculator
    ------------------------------
    You have a calculator that can perform:
    1️⃣ Multiply the current number by 2
    2️⃣ Subtract 1 from the current number

    Given two integers `startValue` and `target`, return the **minimum number of operations**
    to transform startValue into target.

    Approach:
    ---------
    Instead of going forward from startValue → target, we work **backwards**:
    - If target is even, reverse multiply by 2 → divide by 2
    - If target is odd, reverse subtract 1 → add 1
    - Stop when startValue >= target, then the remaining difference can be subtracted directly.
    
    This greedy reverse approach minimizes operations.
*/

int brokenCalc(int startValue, int target) {
    if (startValue >= target) 
        return startValue - target; // Only subtraction needed
    if (target % 2 == 0) 
        return 1 + brokenCalc(startValue, target / 2); // Reverse multiply by 2
    return 1 + brokenCalc(startValue, target + 1);     // Reverse subtract 1
}

int main() {
    int startValue, target;
    cout << "Enter startValue and target: ";
    cin >> startValue >> target;

    int result = brokenCalc(startValue, target);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
