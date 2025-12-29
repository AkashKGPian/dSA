#include <bits/stdc++.h>
using namespace std;
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

string s, t;
int n, m;
int dp[501][501];

int rec(int i, int j) {
    // base cases
    if (i == n) return m - j; // insert all remaining chars of t
    if (j == m) return n - i; // delete all remaining chars of s

    // cache check
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        // characters match ie. no operation
        return dp[i][j] = rec(i + 1, j + 1);
    } else {
        // insert, delete, replace
        int insertOp = 1 + rec(i, j + 1);
        int deleteOp = 1 + rec(i + 1, j);
        int replaceOp = 1 + rec(i + 1, j + 1);
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
}

int main() {
    cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}
