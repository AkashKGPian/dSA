#include <bits/stdc++.h>
using namespace std;

bool check(string st, int start, int end){
    if(start>=end)return 1;
    if(st[start]==st[end] && check(st,start+1,end-1) ) return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string st;
        cin>>st;
        int start=0,end=st.size()-1;
        if(check(st,start,end)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
