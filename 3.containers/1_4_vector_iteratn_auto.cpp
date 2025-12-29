#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v = {1,5,7,9,6,4,3,8,4,5,6};
    //iterator based iteration
    // for(auto it = v.begin() ; it != v.end() ; ++it){
    //     cout<<(*it)<<" ";
    // }

    //ranged based short 
    //auto finds out by itself that value should be of the "int" data type
    for(auto value : v){
        cout<<value<<" ";
    }
    return 0;
}
