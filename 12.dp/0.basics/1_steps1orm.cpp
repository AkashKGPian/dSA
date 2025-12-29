#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int steps;
unordered_map<int, int> memo; // memoization to avoid recomputation

void rec(int level, int cnt) {
    // Prune the path if we've already taken more steps than current best
    if (cnt >= steps || level > n) return;

    // Memoization: if we've already visited this level with fewer or equal steps
    if (memo.count(level) && memo[level] <= cnt) return;
    memo[level] = cnt;

    // Base case
    if (level == n) {
        steps = min(cnt, steps);
        return;
    }

    // Take 1 step
    rec(level + 1, cnt + 1);

    // Take m steps
    rec(level + m, cnt + 1);

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        steps = 1e9;
        memo.clear(); // reset memo for each test case
        rec(0, 0);
        cout << steps << "\n";
    }
    return 0;
}
