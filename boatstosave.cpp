#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Boats to Save People
    ---------------------------------
    You are given an array `people` where people[i] is the weight of the i-th person
    and an integer `limit` which is the weight limit of a boat. Each boat can carry
    at most 2 people at the same time, provided their combined weight is at most `limit`.

    Goal: Find the minimum number of boats to carry every person.

    Approach:
    ---------
    1️⃣ Sort the array of people.
    2️⃣ Use two pointers:
        - i starting from the lightest person
        - j starting from the heaviest person
    3️⃣ If people[i] + people[j] <= limit, both can share a boat (move both pointers)
       Else, the heavier person goes alone (move j)
    4️⃣ Increment the boat count in both cases.
    5️⃣ Continue until i > j
*/

int numRescueBoats(vector<int>& people, int limit) {
    int boats = 0;
    int i = 0, j = people.size() - 1;
    sort(people.begin(), people.end()); // Sort weights

    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            // Both lightest and heaviest person can share a boat
            i++;
            j--;
        } else {
            // Heaviest person goes alone
            j--;
        }
        boats++; // A boat is used in either case
    }

    return boats;
}

int main() {
    int n, limit;
    cout << "Enter number of people: ";
    cin >> n;
    vector<int> people(n);
    cout << "Enter weights of people: ";
    for (int i = 0; i < n; i++) cin >> people[i];

    cout << "Enter boat weight limit: ";
    cin >> limit;

    int result = numRescueBoats(people, limit);
    cout << "Minimum number of boats needed: " << result << endl;

    return 0;
}
