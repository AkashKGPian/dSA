#include <bits/stdc++.h>
using namespace std;
//just for ()

string st;

stack<char> s;
map<char,int> m;
    
bool check(){
    for(int i=0;i<st.size();i++){
        char ch = st[i];
        if(m[ch]>0){
            s.push(ch);
        }else{
            if(!s.empty()){
                s.pop();
            }else{
                return 0;
            }
        }
    }
    if(!s.empty()){
        return 0;
    }else{
        return 1;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>st;
    m.insert({'(',1});
    m.insert({')',-1});
    if(check()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
