#include <bits/stdc++.h>
using namespace std;

//iterate over org elements and select wheather to take it or not
//org se lenge ki nahi lenge = combination

int n,k;
vector<int> arr;

//solution ds 
vector<int>cur;

void rec(int level){
    // cout<<level<<" : ";
    // for(auto v:cur)cout<<v<<" ";cout<<"\n";

    if(level==n){
        if(cur.size()==k){//check
            for(auto v:cur)cout<<v<<" ";cout<<"\n";
        }
        return ;
    }

    //take element in set
    if(cur.size()<k){//choice   //take the elem in the set
        cur.push_back(arr[level]);
        rec(level+1);
        cur.pop_back();
    }
    //dont take element in set
    rec(level+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rec(0);
    return 0;
}
