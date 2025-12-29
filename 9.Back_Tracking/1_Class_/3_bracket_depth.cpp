#include <bits/stdc++.h>
using namespace std;

int n,d;
string curstr;

void rec(int level,int depth){//  WHICH LEVEL?
    //level = index
    if(level==n){
        if(depth==0){
            cout<<curstr<<"\n";
        }
        return ;
    }
    
    
    //standard backtracking problem;
    //'('
    {
        if(depth+1<=d){
            curstr+='(';
            rec(level+1,depth+1);
            curstr.pop_back();
        }
    }
    //')'
    {
        if(depth - 1 >= 0){
            curstr+=')';
            rec(level+1,depth-1);
            curstr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    rec(0,0);
    
    return 0;
}
