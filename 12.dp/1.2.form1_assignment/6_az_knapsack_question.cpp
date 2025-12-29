#include <bits/stdc++.h>
using namespace std;
//implemetation heavy but its just knapsack + printing
//temp me store indices of any of one solution and if soln exist ie temp is not empty then cout<<1 else cout<<-1 
// this was unnecessary but question asked for this 
//that u should make temp and if its not empty then soln exists - easy way would have been ki count!=0 then cout<<1 soln exists

#define ll int64_t

ll dp[101][100100];
vector<int> temp;

int rec(int level, int Wleft, vector<int> &arr){//return the count to achieve the target sum
    //pruning
    if(Wleft<0){
        return 0;
    }
    //base case
    if(level==(int)arr.size()){
        if(Wleft == 0)return 1;
        else return 0;
    }
    //cache check
    if(dp[level][Wleft]!=-1){
        return dp[level][Wleft];
    }
    //transitions
    int ans = 0;
    if(rec(level+1,Wleft-arr[level],arr)==1){
        ans=1;
    }
    if(rec(level+1,Wleft,arr)==1){
        ans=1;
    }
    //save and compute
    return dp[level][Wleft]=ans;
}

void generate(int level, int Wleft, vector<int> &arr){
    //base case
    if(level==(int)arr.size()){
        return ;
    }
    if(rec(level+1,Wleft-arr[level],arr)==1){
        temp.push_back(level);
        generate(level+1,Wleft-arr[level],arr);
        return ;
    }
    if(rec(level+1,Wleft,arr)==1){
        generate(level+1,Wleft,arr);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    vector<vector<int>> ans(queries.size());
    memset(dp,-1,sizeof(dp));
    
    //send queriy at a time by looping
    for(int i=0; i<(int)queries.size(); i++){
        // ans[i].push_back(tempvector)
        temp.clear();

        if (rec(0, queries[i], arr) == 1) {
            generate(0, queries[i], arr);
            ans[i] = temp;
        } else {
            ans[i] = {-1}; // no subset found
        }
    }
    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
