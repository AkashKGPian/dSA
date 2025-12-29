#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //for using lower bound array/vec must be sorted
    vector<int>v={1,5,9,5,7,6,4,8,7,5};
    sort(v.begin(),v.end());
    
    //to verify if the index returned in the output is correct or not
    for(auto value : v)cout<<value<<" ";
    cout<<"\n";


    vector<int>:: iterator it;
    it = lower_bound(v.begin(),v.end(),7);
    cout<<it-v.begin();

    // it=lb(7) symntically it here is the iterator (not equal to ptr)
    // it - arr = return the (int) index in sorted form of the org array 

    return 0;
}
