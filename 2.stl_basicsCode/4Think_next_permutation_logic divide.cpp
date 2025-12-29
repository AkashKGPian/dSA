#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count = 0;

    string s = "0123456789";
    do{
        int numr = stoi(s.substr(0,5));
        int deno = stoi(s.substr(5,5));
        if(numr%deno==0 && numr/deno==n){
            cout<<numr<<" "<<deno<<"\n";
            count++;
        }
    }while(next_permutation(s.begin(),s.end()));
    cout<<count;
    return 0;
}
