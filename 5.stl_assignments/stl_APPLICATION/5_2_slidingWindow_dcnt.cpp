#include <bits/stdc++.h>
using namespace std;

int n,k;

struct dcnt{
    map<int,int> freqm;

    void insert(int x){
        freqm[x]++;
    }
    void remove(int x){
        if(freqm.find(x) != freqm.end()){
            if(freqm[x]==1){
                freqm.erase(x);
            }else{
                freqm[x]--;
            }
        }
    }
    int size(){
        int sz=0;
        for(auto v : freqm){
            sz+=v.second;
        }
        return sz;
    }
    int distinct_count(){
        return freqm.size();
    }

};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    dcnt discnt;    
    for(int i=0;i<n;i++){
        discnt.insert(arr[i]);
        if(i-k>=0) discnt.remove(arr[i-k]);
        if(discnt.size()==k) cout<<discnt.distinct_count()<<"\n";
    }
    return 0;
}
