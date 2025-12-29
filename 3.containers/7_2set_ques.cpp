#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<string>s;
    while(n--){
        string str;
        cin>>str;
        s.insert(str);
    }
    for(string elm : s){
        cout<<elm<<"\n";
    }
    return 0;
}
