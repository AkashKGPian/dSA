#include <bits/stdc++.h>
using namespace std;

int n,k;
string str;
int depth;

bool is_reached;

void recfill(int level){
    cout<<level<<" : ";
    cout<<str<<"\n";
    if(level==n){
        if(depth==0 && is_reached){
            cout<<"a "<<str<<"\n";
            is_reached=0;
        }
        return;
    }
    //(
    {
        if(depth+1<=k){
            depth++;
            if(depth==k)is_reached=1;
            str+='(';
            recfill(level+1);
            depth--;
            str.pop_back();
        }
    }
    //)
    {
        if(depth-1>=0){
            depth--;
            str+=')';
            recfill(level+1);
            str.pop_back();
            depth++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    recfill(0);
    return 0;
}
