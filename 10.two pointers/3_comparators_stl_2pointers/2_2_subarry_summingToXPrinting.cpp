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
    long long cnt=0;//cuz if all 10^5 are 0 then 
    map<int,vector<int>> mp;//har ek elem ka ek vector hai which stores the indices of L
    mp[0].push_back(-1);//at index -1 there is a '0'
    for(int i=0;i<n;i++){
        cnt+=mp[p[i]-x].size();
        for(auto v : mp[p[i]-x]){
            cout<<v+1<<","<<i<<endl;
        }
        mp[p[i]].push_back(i);
    }
    cout<<cnt;
    return 0;
}
