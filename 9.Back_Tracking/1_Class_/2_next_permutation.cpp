#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> perm;

void printer(int level){
    cout<<level<< " : {";
    for(auto i : perm){
        cout<<i<<", ";
    }
    cout<<"}\n";
}

int is_valid(int idx, int val){
    for(int pidx=0;pidx<idx;pidx++){
        int pval = perm[pidx];
        if(pval==val){
            return 0;
        }
    }
    return 1;
}

void next_perm(int index){//level is index
    //base case
    if(index==n){
        printer(index);
        return ;
    } 
    for(int val=0;val<n;val++){//choice
        if(is_valid(index,val)){
            perm.push_back(val);
            next_perm(index+1);
            perm.pop_back();
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    next_perm(0);
    return 0;
}
