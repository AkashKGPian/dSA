#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> vec = {1,5,8,6,9,5,7,4,5};
    //range based loop
    //iterating through the vector using variable i
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i];
    // }

    //range based loop--SHORT CUT
    for(int value : vec){
        cout<<value<<" ";
    }

    
    
    return 0;
}
