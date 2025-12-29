#include <bits/stdc++.h>
using namespace std;
//cf

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    //to uphold the order
    vector<string> v;
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        v.push_back(st);
    }
    reverse(v.begin(),v.end());

    //to store the unique elem
    set<string> s;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
    }
    
    //now print the unique elm in order
    for(int i=0;i<n;i++){
        if(s.find(v[i])!=s.end()){
            cout<<v[i]<<"\n";
            s.erase(v[i]);
        }
    }
    
    return 0;
}
