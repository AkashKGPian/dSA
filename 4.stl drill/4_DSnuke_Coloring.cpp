#include <bits/stdc++.h>
using namespace std;
//atcoder

#define int long long

int sum( vector<vector<int>> v, int a, int b){
    int sum_v=0;
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            sum_v += v[i][j];
        }
    }
    return sum_v;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    vector<vector<int>> v(h, vector<int>(w));
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        --a,--b;
        v[a][b]=1;
    }
    map<int,int> m;//sum,freq_count
    for(int i=0;i<=h-3;i++){
        for(int j=0;j<=w-3;j++){
            int black = sum(v,i,j);
            m[black] = m[black] + 1;
        }
    }

    // Total number of 3x3 subrectangles
    int total = (h - 2LL) * (w - 2LL);
    
    for (int i = 0; i <= 9; i++) {
        if (i == 0) {
            // 0 black = total - sum of all non-zero
            
            for (int j = 1; j <= 9; j++) {
                total-= m[j];
            }
            cout << total << "\n";
        } else {
            cout << m[i] << "\n";
        }
    }
    return 0;
}
