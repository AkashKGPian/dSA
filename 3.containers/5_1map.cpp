#include <bits/stdc++.h>
using namespace std;

void print(map<int,string>& m){
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //uses red black tree for sorting and storing keys
    map<int,string> m;
    m[1]="abc";
    m[3]="cdc";
    m[2]="def";
    m.insert({7,"fgf"});
    // map<int,string> :: iterator it;
    // for(it = m.begin(); it != m.end(); ++it){
    //     cout<< (*it).first<<" "<< it->second<<"\n";
    // }
    auto it = m.find(7);
    if(it==m.end()){
        cout<<"this key doesnt exist in the map";
    }else{
        print(m);
    }
    
    return 0;
}
