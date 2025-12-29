//given n, n strings print unique string in lexicographical order wiht their freq;
//n<=10^5  |s|<=100
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,int>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        // m[str] = m[str] + 1;
        m[str]++;
    }
    for(auto pr : m){
        cout<<pr.first <<" "<<pr.second<<"\n";
    }
    return 0;
}
