#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    cin>>st;
    //({}[]{[]})
    map<char,int>mp;
    mp['(']=1;mp[')']=-1;
    mp['{']=2;mp['}']=-2;
    mp['[']=3;mp[']']=-3;
    
    stack<char> s;
    int is_balanced=1;
    
    for(char v : st){
        if(mp[v]>0){
            s.push(v);
        }else{
            if(s.empty()){
                is_balanced=0;
                break;
            }else{
                if(mp[s.top()]+mp[v]==0){
                    s.pop();
                }else{
                    is_balanced=0;
                    break;
                }
            }
        }
    }
    if(s.empty() && is_balanced){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}