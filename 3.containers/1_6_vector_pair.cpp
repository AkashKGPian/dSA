#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int>> vp = {{1,3},{8,6},{5,7}};
    for(pair<int,int> &value : vp){//& infornt of value means refence to the org vector ie now the varible value doesnt store the copy of the elements instead it stores the org
        cout<<value.first<<" - "<<value.second<<"\n";
    }
    return 0;
}
