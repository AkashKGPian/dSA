#include <bits/stdc++.h>
using namespace std;
//seemed hard for me

int A[105];
int dp[105][105];
int n;

// recursive DP
int solve(int l, int r) {
    if (l > r) return 0;          // empty interval
    if (l == r) return 1;         // single gemstone

    int &ans = dp[l][r];
    if (ans != -1) return ans;

    // 1. remove A[l] alone
    ans = 1 + solve(l+1, r);

    // 2. if next is same, remove A[l] + A[l+1] together
    if (l+1 <= r && A[l] == A[l+1]) {
        ans = min(ans, 1 + solve(l+2, r));
    }

    // 3. merge with some A[k] == A[l]
    for (int k = l+2; k <= r; k++) {
        if (A[l] == A[k]) {
            ans = min(ans, solve(l+1, k-1) + solve(k+1, r));
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        memset(dp, -1, sizeof(dp));
        cout << solve(1, n) << "\n";
    }
    return 0;
}
