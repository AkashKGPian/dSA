#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100010];

// dp[level][last_taken+1]
// last_taken = -1 mapped to 0
// last_taken = 0 mapped to 1
// last_taken = i mapped to i+1
int dp[100010][102];   // if n <= 100, change accordingly
// If n can be up to 100000, this recursion method is NOT feasible.
// For large n use O(n log n) solution instead.

int rec(int level, int last_taken){
    // base case
    if(level == n) return 0;

    // cache check
    if(dp[level][last_taken + 1] != -1)
        return dp[level][last_taken + 1];

    // skip current element
    int ans = rec(level + 1, last_taken);

    // take current element if valid
    if(last_taken == -1 || arr[level] > arr[last_taken]){
        ans = max(ans, 1 + rec(level + 1, level));
    }

    // save and return
    return dp[level][last_taken + 1] = ans;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0, -1);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
