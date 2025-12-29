#include <bits/stdc++.h>
using namespace std;
//atcoder

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> str;
    int n;
    cin>>n;
    while(n--){
        string st;
        cin>>st;
        str.insert(st);
    }
    cout<<str.size();
    return 0;
}
