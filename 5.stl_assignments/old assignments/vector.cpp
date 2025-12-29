#include<bits/stdc++.h>
using namespace std;

void add(vector<int> &v, int x){
    v.push_back(x);
    return ;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        vector<int>v;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                int x;
                cin>>x;
                add(v,x);
            }else if(s=="remove" && !v.empty()){
                v.pop_back();
            }else if(s=="print"){
                int x;
                cin>>x;
                cout<<(( x>=0 && x<v.size() )? v[x] : 0)<<"\n";
            }else if(s=="clear"){
                v.clear();
            }
        }
    }
    
    return 0;
}