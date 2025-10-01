#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Minimum Average Waiting Time
    ----------------------------------------
    Given an array `bt` representing the burst times of N customers in a restaurant,
    find the minimum average waiting time if customers are served in an order that 
    minimizes the waiting time.

    Approach:
    ---------
    1️⃣ Sort the burst times in ascending order.
    2️⃣ Initialize cumulative time `tt = 0` and total waiting time `wt = 0`.
    3️⃣ For each customer:
        - Add the current cumulative time `tt` to `wt` (waiting time for this customer)
        - Increment cumulative time: `tt += bt[i]`
    4️⃣ Return the integer division of total waiting time by number of customers.

    This is the greedy approach: serve the shortest job first (SJF) to minimize waiting time.
*/

long long minimumAverageWaitingTime(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    long long wt = 0;   // total waiting time
    long long tt = 0;   // cumulative time
    int n = bt.size();
    for (int i = 0; i < n; i++) {
        wt += tt;
        tt += bt[i];
    }
    return wt / n; // integer division for average
}

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;

    vector<int> bt(n);
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) cin >> bt[i];

    long long avgWaitTime = minimumAverageWaitingTime(bt);
    cout << "Minimum Average Waiting Time: " << avgWaitTime << endl;

    return 0;
}
