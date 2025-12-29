#include<bits/stdc++.h>
using namespace std;

void solve1(int n){
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
    return ;
}

void solve2(int n){
    int count = 0;
    
    for(int abcde=1234 ; abcde<=98765/n; abcde++){
        int fghij = n*abcde;
        set<int> st;
        
        int temp = abcde;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp/=10;
        }
        
        temp = fghij;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp/=10;
        }
        
        if(st.size()==10){
            cout<<abcde<<" "<<fghij<<"\n";
            count++;
        }
        
    }
    cout<<count;
    return ;
}

int main(){
    int n;
    cin>>n;
    solve1(n);
    // solve2(n);
    
    return 0;
}
