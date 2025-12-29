//given n, n strings and q queries to which u need to freq;
//n<=10^5  |s|<=100
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;

    unordered_map<string,int>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        // m[str] = m[str] + 1;
        m[str]++;
    }
    while(q--){
        string s;
        cin>>s;
        cout<<m[s]<<"\n";
    }
    return 0;
}
