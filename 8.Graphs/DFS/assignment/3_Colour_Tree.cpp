#include <bits/stdc++.h>
using namespace std;
//was supposed to be a hard question
//u saw the answer

//find the chromatic color no. required to make it bipartitie

vector<vector<int>> g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int max_deg = 0;
    for(int i=1;i<=n;i++){
        max_deg = max(max_deg,(int)g[i].size());
    }
     // Minimum colors required = max degree + 1
    cout << max_deg + 1 << endl;
    return 0;
}
