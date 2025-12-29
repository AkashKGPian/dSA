#include<bits/stdc++.h>
using namespace std;
//atcoder f lcs
string s,t;
int n,m;
int dp[3010][3010];
int back[3010][3010];

int rec(int l1, int l2){
    //pruning
    //base case
    if(l1==n || l2==m)return 0;
    //cache check
    if(dp[l1][l2]!=-1){
        return dp[l1][l2];
    }
    //transitions
    int ans=0;
    if(l1<n){
        if(rec(l1+1,l2)>ans){
            ans=rec(l1+1,l2);
            back[l1][l2]=1;//only updating this back for the max rec(l1,l2+1) and not for every other case
        }
    }
    if(l1<n){
        if(rec(l1,l2+1)>ans){
            ans=rec(l1,l2+1);
            back[l1][l2]=2;//thats why we have used the above if condn
        }
    }
    if(l1<n && l2<m && s[l1]==t[l2]){
        if(1+rec(l1+1,l2+1)>ans){
            ans=1+rec(l1+1,l2+1);
            back[l1][l2]=0;
        }
    }
    //save and return 
    return dp[l1][l2]=ans;
}

void generate(int l1, int l2){
    //base case
    if(l1==n || l2==m)return;
    int ch = back[l1][l2];
    if(ch==0){
        cout<<s[l1];
        generate(l1+1,l2+1);
    }else if(ch==1){
        generate(l1+1,l2);
    }else{
        generate(l1,l2+1);
    }
}

int main(){
    cin>>s>>t;
    n=s.length();
    m=t.length();
    memset(dp,-1,sizeof(dp));
    memset(back,-1,sizeof(back));
    rec(0,0);
    generate(0,0);
    return 0;
}