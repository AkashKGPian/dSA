#include<bits/stdc++.h>
using namespace std;
//atcoder f lcs
string s,t;
int n,m;
int dp[3010][3010];
int back[3010][3010];

int rec(int i, int j){
    //pruning
    //base case
    if(i==n || j==m)return 0;
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //transitions
    int ans=0;
    if(rec(i+1,j)>ans){
        ans=rec(i+1,j);
        back[i][j]=1;//only updating this back for the max rec(i,j+1) and not for every other case
    }
    if(rec(i,j+1)>ans){
        ans=rec(i,j+1);
        back[i][j]=2;//thats why we have used the above if condn
    }
    if(s[i]==t[j]){
        if(1+rec(i+1,j+1)>ans){
            ans=1+rec(i+1,j+1);
            back[i][j]=0;
        }
    }
    //save and return 
    return dp[i][j]=ans;
}

void generate(int i, int j){
    //base case
    if(i==n || j==m)return;
    int ch = back[i][j];
    if(ch==0){
        cout<<s[i];
        generate(i+1,j+1);
    }else if(ch==1){
        generate(i+1,j);
    }else{
        generate(i,j+1);
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