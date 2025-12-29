#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        while(q--){
            string st;
            cin >> st;
            stack<int> s;
            if(st=="add"){
                int x;
                cin>>x;
                s.push(x);
            }
            if(st=="remove" && !s.empty()){
                s.pop();
            }
            if(st=="print"){
                if(!s.empty()){
                    cout<<s.top()<<"\n";
                }else{
                    cout<<"0"<<"\n";
                }
            }

        }

    }
    
    return 0;
}