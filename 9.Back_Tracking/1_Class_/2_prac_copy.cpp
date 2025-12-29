#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> npr;//index are the rows
vector<int>arr;

void printer(int level){
    cout<<level<<" : ";
    cout<<"npr : { ";
    for(auto v : npr){
        cout<<v<<" ,";
    }
    cout<<" }\n";
}

bool is_valid(int index,int val){
    //GIVEN CURRENT ROW -now iterate all the levels/rows before it//oriw
    for(int pidx=0; pidx<index; pidx++){
        int pval = npr[pidx];
        if(pval==val){
            return 0;
        }
    }
    return 1;
}

void rec(int level){//  WHICH LEVEL?
    //level here is index which stores the arr elem
    //base case
    printer(level);
    if(level==n){
        cout<<"--------------\n";
        printer(level);
        cout<<"--------------\n";
        return ;
    }
    //recursive part
    for(auto col=arr.begin(); col!=arr.end(); col++){// WHAT ARE THE CHOICES - FOR AND ORDERED PERMUTATION 
        if(is_valid(level,*col)){//CHECK
            //MOVE
            npr.push_back(*col); 
            rec(level+1);
            npr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    rec(0);
    
    return 0;
}
