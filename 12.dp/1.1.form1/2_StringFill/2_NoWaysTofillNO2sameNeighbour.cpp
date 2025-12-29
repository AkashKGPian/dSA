#include<bits/stdc++.h>
using namespace std;
//find the no. of ways to fill '?' such that no two neigh is a same char

string st;
int dp[100100][4];

int rec(int i, int prev){//0-> A ; 1->B..
    //pruning
    //base case
    if(i==st.size()){
        //u have filled all the blanks 0 to n-1 @n 
        return 1;
    }
    //cache check
    //prev!=-1 is imp u cant access '-ve' index
    if(prev!=-1 && dp[i][prev]!=-1){
        return dp[i][prev];
    }
    //calcuate
    int ans=0;//for every level a new var ans is created
    if(st[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(ch==prev)continue;
            ans+=rec(i+1,ch);
        }
    }else{
        if((st[i]-'A')==prev){
            return 0;
        }else{
            ans = rec(i+1,(st[i]-'A'));
        }
    }
    //save and return 
    if(prev!=-1)dp[i][prev]=ans;
    return ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>st;
    cout<<rec(0,-1);
    return 0;
}








// my code
// #include<bits/stdc++.h>
// using namespace std;
// // ??AB?C??D? how many ways are there to fill ?
// int n;
// string st;
// int dp[100100][4];

// int rec(int i, int prev){
//     //pruning 
//     //base case
//     if(i==n){
//         return 1;
//     }
//     //cache check
//     if(prev!=-1 && dp[i][prev]!=-1){
//         return dp[i][prev];
//     }
//     //calculate
//     int noWays=0;
//     if(st[i]=='?'){
//         for(int ch=0;ch<4;ch++){
//             if(ch==prev)continue;
//             noWays += rec(i+1,ch);
//         }
//     }else{
//         if((st[i]-'A')!=prev){
//             noWays = rec(i+1,(st[i]-'A'));
//         }else{
//             return 0;
//         }
//     }
//     //save and return 
//     if(prev!=-1) dp[i][prev]=noWays;
//     return noWays;
// }

// int main(){
//     cin>>n>>st;
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(0,-1)<<"\n";
//     return 0;
// }