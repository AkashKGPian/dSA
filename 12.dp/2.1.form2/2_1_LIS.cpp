#include<bits/stdc++.h>
using namespace std;
//lis
//logic == form2

int n;
int arr[100100];
int dp[100100];
//returns best till for every index #

//tc = O(n2)
int rec(int level){//returns the best ___LIS___ ending/possible at index = level x
    //pruning
    // if(level<0)return 0;
    //base case
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans=1;
    for(int last_idxtaken=0;last_idxtaken<level;last_idxtaken++){
        //if u can take the element
        if(arr[last_idxtaken]<arr[level]){
            ans = max(ans,1+rec(last_idxtaken));//cnt++ to the lis possible ie (x + 1)
        }
        //if u cant then no step needed
    }
    //sava and return 
    return dp[level] = ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    
    // //debugging
    // for(int i=0;i<n;i++){
    //     cout<<"LIS @ index "<<i<<" is : "<<rec(i)<<"\n";
    // }

    int best=0;
    for(int i=0;i<n;i++){
        best=max(best,rec(i));
    }
    cout<<best<<"\n";
    return 0;
}