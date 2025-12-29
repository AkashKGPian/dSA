#include <bits/stdc++.h>
using namespace std;
//same prev ques count instead of 1/0

/*
Task: Count how many times "0100" appears as a subsequence in the given binary string.

Definitions:
- Subsequence: We can delete some characters (possibly none) and keep the relative order.
- For example: 
    String = 0 1 0 0
    Subsequences that equal "0100" = 1 (only the full string itself).
*/

int n;
string t = "0100"; // target subsequence
int arr[100010];   // input binary string (as integers 0/1)
long long dp[100010][5]; 
// dp[level][match] = number of ways to form subsequence t[match..end]
// from position "level" onwards

long long rec(int level, int match) {
    // Base case 1: If we matched the full "0100"
    if (match == 4) {
        return 1;  // one valid subsequence found
    }

    // Base case 2: If we reached end of input but haven't matched "0100"
    if (level == n) {
        return 0;  // no subsequence here
    }

    // Cache check
    if (dp[level][match] != -1) {
        return dp[level][match];
    }

    long long ans = 0;

    // Option 1: skip arr[level]
    ans += rec(level + 1, match);

    // Option 2: take arr[level] if it matches the next needed character
    if (arr[level] == (t[match] - '0')) {
        ans += rec(level + 1, match + 1);
    }

    return dp[level][match] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // each element is 0 or 1
    }

    // Initialize DP with -1 (uncomputed states)
    memset(dp, -1, sizeof(dp));

    // Start from position 0, match index 0
    cout << rec(0, 0) << "\n";

    return 0;
}
