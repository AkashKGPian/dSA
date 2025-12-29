#include <bits/stdc++.h>
using namespace std;
//o(Nlogk)
// 9 3
// 3 1 5 3 2 5 9 1 2

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;    
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
    multiset<int> mt;
    for(int i=0;i<n;i++){
        mt.insert(arr[i]);
        if(i-k>=0) mt.erase(mt.find(arr[i-k]));
        if(mt.size()==k) cout<<*mt.begin()<<"\n";
    }
    return 0;
}
