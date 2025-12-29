#include <bits/stdc++.h>
using namespace std;
//cf

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,int> m;
    while(n--){
        string s;
        cin>>s;
        m[s] = m[s] + 1;
        if(m[s]==1){
            cout<<"OK"<<"\n";
        }else{
            cout<<s<<m[s]-1<<"\n";
        }
    }
    return 0;
}
