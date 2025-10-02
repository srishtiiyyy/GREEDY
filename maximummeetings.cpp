#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Meetings in One Room

Given start and end times of N meetings, determine the maximum number of meetings
that can be scheduled in one room such that no two meetings overlap.

Approach:
1. Pair each meeting's start and end times.
2. Sort meetings by their end times (greedy approach).
3. Initialize the first meeting as selected and set its end as the current limit.
4. Iterate through remaining meetings:
   - If a meeting starts after the limit, select it and update the limit.
5. Return the total count of selected meetings.
This is a standard greedy algorithm for activity selection.
*/

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> meetings;
    
    for (int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i]});
    }

    // Sort by end time
    sort(meetings.begin(), meetings.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });

    int limit = meetings[0].second; // End of first meeting
    int count = 1; // First meeting selected

    for (int i = 1; i < n; i++) {
        if (meetings[i].first > limit) {
            limit = meetings[i].second;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<int> start(n), end(n);
    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) cin >> start[i];
    cout << "Enter end times: ";
    for (int i = 0; i < n; i++) cin >> end[i];

    cout << "Maximum number of non-overlapping meeting " 
         << maxMeetings(start, end) << endl;

    return 0;
}
