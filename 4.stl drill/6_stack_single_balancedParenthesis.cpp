#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
    unordered_map<char,int> m = {{'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3}};
    stack<char>stk;
        //  {[( ])}
    for( auto elm : s){
        if(m[elm]<0){
            stk.push(elm);
        }else{
            if(stk.empty())return "NO";
            char top = stk.top();
            stk.pop();
            if(m[elm]+m[top]!=0){
                return "NO";
            }
        }
    }
    if(!stk.empty()){
        return "NO";
    }else{
        return "YES";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string st;
    cin>>st;

    string result = isBalanced(st);
    cout<<result;
    
    return 0;
}
