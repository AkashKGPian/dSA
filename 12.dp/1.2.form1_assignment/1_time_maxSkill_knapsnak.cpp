#include<bits/stdc++.h>
using namespace std;
//find the max skill that can be achieved with t_Taken<=X and total elem taken <=k
//this method is fine if we have a single query as the query incresae the cache stored in dp array turns invalid 
//because of the logic of t_taken(taking time left as in below code is better way for handling multiple queries)
const int INF=1e9;

int n,X,k;
int time_[1010];
int skill_val[1010];
int dp[1001][1001][101];

int rec(int i, int t_taken, int item_taken){
    //pruning
    //base case
    if(i == n){
        return 0;
    }
    //cache check
    if(dp[i][t_taken][item_taken]!=-1){
        return dp[i][t_taken][item_taken];
    }
    //compute/transitions
    //take and not take
    int ans = rec(i+1,t_taken,item_taken);
    if(t_taken+time_[i]<=X && item_taken+1<=k){
        ans = max(ans,skill_val[i]+rec(i+1,t_taken+time_[i],item_taken+1));
    }
    //save and return 
    return dp[i][t_taken][item_taken]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>X>>k;
    for(int i=0;i<n;i++){
        cin>>time_[i];
    }
    for(int i=0;i<n;i++){
        cin>>skill_val[i];
    }
    cout<<rec(0,0,0);
    return 0;
}

//same but a bit different

// #include<bits/stdc++.h>
// using namespace std;

// const int INF=1e9;

// int n,X,k;
// int time_[1010];
// int skill_val[1010];
// int dp[1001][1001][101];

// int rec(int i, int t_taken, int item_taken){
//     //pruning
//     if(t_taken<0 || item_taken>k)return -INF;
//     //base case
//     if(i == n){
//         return 0;
//     }
//     //cache check
//     if(dp[i][t_taken][item_taken]!=-1){
//         return dp[i][t_taken][item_taken];
//     }
//     //compute/transitions
//     //take and not take
//     int ans = rec(i+1,t_taken,item_taken);
//     if(time_[i]<=t_taken && item_taken+1<=k){
//         ans = max(ans,skill_val[i]+rec(i+1,t_taken-time_[i],item_taken+1));
//     }
//     //save and return 
//     return dp[i][t_taken][item_taken]=ans;
// }

// int main(){
//     memset(dp,-1,sizeof(dp));
//     cin>>n>>X>>k;
//     for(int i=0;i<n;i++){
//         cin>>time_[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>skill_val[i];
//     }
//     cout<<rec(0,X,0);
//     return 0;
// }