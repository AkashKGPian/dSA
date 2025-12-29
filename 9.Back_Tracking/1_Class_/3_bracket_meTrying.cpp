#include <bits/stdc++.h>
using namespace std;

int n;
int d;
vector<char> brak;

void printer(){
    for(auto i : brak){
        cout<<i<<" ";
    }
    cout<<"\n";
}

void fillarray(int index, int depth){
    //base case
    if(index==n){
        if(depth==0){
            printer();
        }
        return ;
    }
    //recursive case
    //(
    {
        if(depth+1<=d){
            brak.push_back('(');
            fillarray(index+1,depth+1);
            brak.pop_back();
        }
    }
    //)
    {
        if(depth-1>=0){
            brak.push_back(')');
            fillarray(index+1,depth-1);
            brak.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    fillarray(0,0);
    return 0;
}
