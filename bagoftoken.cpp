#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Bag of Tokens
    -----------------------------------
    You are given an initial power and a set of tokens with values.
    You can perform two operations:
    
    1️⃣ If you have at least `tokens[i]` power, you can play it face up:
       - Power decreases by `tokens[i]`
       - Score increases by 1
    2️⃣ If you have at least 1 score, you can play it face down:
       - Power increases by `tokens[i]`
       - Score decreases by 1

    Goal: Maximize your score after playing any number of tokens.

    Approach:
    ---------
    - Sort the tokens.
    - Use two pointers: i (start), j (end)
    - While i <= j:
        - If you have enough power for tokens[i], play face up
        - Else if score >= 1, play tokens[j] face down to gain power
        - Else break
    - Track maximum score seen
*/

int bagOfTokensScore(vector<int>& tokens, int power) {
    int n = tokens.size();
    sort(tokens.begin(), tokens.end()); // sort for greedy approach

    int i = 0, j = n - 1;
    int score = 0, maxScore = 0;

    while (i <= j) {
        if (power >= tokens[i]) {
            // Play face up
            power -= tokens[i];
            score++;
            i++;
            maxScore = max(maxScore, score);
        } 
        else if (score >= 1) {
            // Play face down
            power += tokens[j];
            score--;
            j--;
        } 
        else {
            break; // can't play any more
        }
    }

    return maxScore;
}

int main() {
    int n, power;
    cout << "Enter number of tokens: ";
    cin >> n;
    vector<int> tokens(n);
    cout << "Enter token values: ";
    for (int i = 0; i < n; i++) cin >> tokens[i];

    cout << "Enter initial power: ";
    cin >> power;

    int result = bagOfTokensScore(tokens, power);
    cout << "Maximum score achievable: " << result << endl;

    return 0;
}
