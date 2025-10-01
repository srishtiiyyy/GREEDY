#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Break a Palindrome
    ---------------------------------
    Given a palindromic string, you need to replace **exactly one character**
    to make the string **not a palindrome** and also **lexicographically smallest**.
    
    Goal: Return the resulting string. If impossible (single-character palindrome), return "".

    Approach:
    ---------
    1️⃣ If the string length is 1, return "" (cannot break a single-char palindrome).
    2️⃣ Traverse the first half of the string:
        - If a character is not 'a', change it to 'a' and return immediately.
    3️⃣ If all characters in the first half are 'a', change the **last character** to 'b'.
       This guarantees the string is no longer a palindrome and is lexicographically minimal.
*/

string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    if (n == 1) return ""; // Single character palindrome cannot be changed

    for (int i = 0; i < n / 2; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a'; // Replace first non-'a' char with 'a'
            return palindrome;
        }
    }

    // If all first half characters are 'a', change the last char to 'b'
    palindrome[n - 1] = 'b';
    return palindrome;
}

int main() {
    string s;
    cout << "Enter palindrome string: ";
    cin >> s;

    string result = breakPalindrome(s);
    if (result == "") {
        cout << "Cannot break palindrome (single-character string)" << endl;
    } else {
        cout << "Modified string: " << result << endl;
    }

    return 0;
}
