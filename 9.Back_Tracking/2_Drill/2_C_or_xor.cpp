#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

// solution curr ds
void rec(int level, int xor_inv; int cur_or_inv){
    if(level==n){

    }
    //
    rec(level+1,xor_inv,cur_or_inv || arr[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rec(0,)
    return 0;
}
