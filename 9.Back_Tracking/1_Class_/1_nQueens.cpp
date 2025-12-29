#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> queens;//index are the rows
int cnt=0;


void printer(int level){
    cout<<level<<" : ";
    cout<<"queens : { ";
    for(auto v : queens){
        cout<<v<<" ,";
    }
    cout<<" }\n";
    cnt++;
}

bool is_valid(int row,int col){
    //GIVEN CURRENT ROW -now iterate all the levels/rows before it//oriw
    for(int prow=0;prow<row;prow++){
        int pcol = queens[prow];
        if( pcol==col || abs(prow-row)==abs(pcol-col) ){
            return 0;
        }
    } 
    return 1;
}

void rec(int level){//  WHICH LEVEL?
    //base case
    // printer(level);
    if(level==n){
        printer(level);
        return ;
    }
    //recursive part
    for(int col=0; col<n; col++){// WHAT ARE THE CHOICES - FOR AND ORDERED PERMUTATION 
        if(is_valid(level,col)){//CHECK
            //MOVE
            queens.push_back(col); 
            rec(level+1);
            queens.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rec(0);
    cout<<"Total no. of ways are: "<<cnt<<"\n";
    
    return 0;
}
