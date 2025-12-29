#include <bits/stdc++.h>
using namespace std;

// 5 0
// 1 -1 1 -1 0

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i)p[i]+=p[i-1];//built prefix sum directly
    }
    //but this prefix sum does have 0 at the index 0;
    int cnt=0;
    map<int,int> mp;
    mp[0]++;
    for(int i=0;i<n;i++){
        cnt+=mp[p[i]-x];
        mp[p[i]]++;
    }
    cout<<cnt;
    return 0;
}
