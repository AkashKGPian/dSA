#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        multiset<int> mt;
        for(int i=1;i<=n;i++){
            mt.insert(arr[i]);
            if(i-k>0) mt.erase(mt.find(arr[i-k]));
            if(mt.size()==k){
                auto it = --mt.end();
                cout<<*it<<" ";
            }
        }
        cout<<"\n";
        mt.clear();
    }
    return 0;
}