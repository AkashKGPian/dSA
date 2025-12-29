#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>queens;

void printer(){
    cout<< "queens : {";
    for(auto v : queens){
        cout<<v<<", ";
    }
    cout<<"}\n";
}

bool is_valid(int row,int col){
    for(int prow=0; prow<row; prow++){
        int pcol=queens[prow];
        if(pcol==col || abs(pcol-col)==abs(prow-row))return 0;
    }
    return 1;
}

void rec(int level){
    //base part
    if(level==n){
        printer();
        return ;
    }
    
    //recursive part
    for(int col=0 ; col<n ; col++){
        if(is_valid(level,col)){
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rec(0);
    return 0;
}
