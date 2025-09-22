#include <bits/stdc++.h>
using namespace std;

/*
Problem: Assign Cookies
- g[i] = greed factor of child i
- s[j] = size of cookie j
- Each child can get at most one cookie
- Return maximum number of content children
*/

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); // Sort greed factors
    sort(s.begin(), s.end()); // Sort cookie sizes

    int i = 0; // pointer for children
    int j = 0; // pointer for cookies

    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            // This cookie satisfies child i
            i++;
            j++;
        } else {
            // Cookie too small, try next bigger cookie
            j++;
        }
    }
    return i; // number of satisfied children
}

int main() {
    vector<int> g = {1, 2, 3};  // Greed factors
    vector<int> s = {1, 1};     // Cookie sizes

    cout << "Max content children: " << findContentChildren(g, s) << endl;
    return 0;
}
