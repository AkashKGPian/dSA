#include <bits/stdc++.h>
using namespace std;

int cnt;
int a,b;

bool palin(string st, auto start, auto end){
    if(start>=end)return 1;
    if(*start==*end)palin(st,start+1,end-1);
    else return 0;
}

bool is_palindrome(int a){
    if(a<10)return 1;
    string st = to_string(a);
    return palin(st,st.begin(),--st.end());
}

bool is_prime(int a){
    if(a==2)return 1;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)return 0;
    }
    return 1;
}

int countill(int b){
    int cnt=0;
    for(int i=2;i<=b;i++){
        if(is_palindrome(i)){
            if(is_prime(i))cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    int count;
    if(is_palindrome(a) && is_prime(a) ){
        count = countill(b)-countill(a)+1;
    }else{
        count = countill(b)-countill(a);
    }
    cout<<count<<"\n";
    return 0;
}

