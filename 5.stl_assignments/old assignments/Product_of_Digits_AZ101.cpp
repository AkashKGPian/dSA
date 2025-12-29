#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        bool hasZero=false;
        long long product=1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0)hasZero=true;
            else product=(product*v[i])%MOD;
        }
        cout<<(hasZero? 0 : product) <<"\n";
    }

    return 0;
}
