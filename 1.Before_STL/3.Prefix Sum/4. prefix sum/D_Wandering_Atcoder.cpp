#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int prefix[n+2]{};
    for(int i=1;i<=n;i++){
        cin>>prefix[i];
    }
    int max_el=0;
    for(int i=1;i<=n;i++){
        prefix[i]+=prefix[i-1];
        max_el+=max(max_el,prefix[i]);
    }
    cout<<max_el;
    return 0;
}
