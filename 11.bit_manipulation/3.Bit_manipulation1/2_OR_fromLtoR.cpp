#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long

int rangeBitwiseOR(int l, int r){
    int shift=0;
    bitset<64>L,R;
    L=l;R=r;
    while( L.to_ullong() < R.to_ullong() ){
        L >>= 1;
        R >>= 1;
        shift++;
    }
    while(shift--){
        L <<= 1;
        L[0]=1;
    }
    return L.to_ullong();
}

signed main(){
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<rangeBitwiseOR(l,r)<<"\n";
    }
    return 0;
}