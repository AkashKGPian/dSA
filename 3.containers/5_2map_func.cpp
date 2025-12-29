#include <bits/stdc++.h>
using namespace std;

void print(map<int,string> m){
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int,string> m;
    m[1]="abc";
    m[3]="cdc";
    m[2]="def";
    m.insert({7,"fgf"});
    m.erase(3);
    print(m);
    cout<<"\n";
    m.erase(8);//o(logn)
    print(m);
    cout<<"\n";
    auto it = m.find(2);
    // m.erase(it);
    // print(m);

    //if it points at m.end() then it gives segmentation error that why there should be an check
    if(it != m.end()){
        m.erase(it);
        print(m);
    }
    m.clear();
    return 0;
}
