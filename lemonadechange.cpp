/*
Question: Lemonade Change (Leetcode 860)

You are a lemonade seller. Each lemonade costs $5.
Customers are standing in a line and pay with one of three bills: $5, $10, or $20.
- You must give back the correct change to each customer immediately.
- Initially, you have no money.

Return true if you can provide change to all customers, otherwise false.

Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation:
- Customer 1 pays $5 → keep it (now have: $5=1, $10=0)
- Customer 2 pays $5 → keep it (now: $5=2, $10=0)
- Customer 3 pays $5 → keep it (now: $5=3, $10=0)
- Customer 4 pays $10 → give back one $5 (now: $5=2, $10=1)
- Customer 5 pays $20 → best to give back $10 + $5 (now: $5=1, $10=0)
✅ Worked for all customers.

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation:
- Customer 1 pays $5 → keep it (now: $5=1, $10=0)
- Customer 2 pays $5 → keep it (now: $5=2, $10=0)
- Customer 3 pays $10 → give back one $5 (now: $5=1, $10=1)
- Customer 4 pays $10 → give back one $5 (now: $5=0, $10=2)
- Customer 5 pays $20 → need $15 change, but no $5 left ❌
So answer is false.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if we can give change to all customers
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } 
        else if (bill == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } 
        else { // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } 
            else if (five >= 3) {
                five -= 3;
            } 
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    
    if (lemonadeChange(bills)) 
        cout << "Possible to give change to all customers\n";
    else 
        cout << "Not possible to give change\n";

    return 0;
}
