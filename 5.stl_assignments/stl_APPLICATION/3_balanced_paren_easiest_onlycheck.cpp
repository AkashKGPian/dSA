#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    cin>>st;
    
    int depth=0;
    bool is_balanced=1;
    for(char v : st){
        if(v=='('){
            depth++;
        }else{
            depth--;
        }
        if(depth<0){
            is_balanced=0;
            break;
        }
    }
    if(is_balanced && depth==0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
