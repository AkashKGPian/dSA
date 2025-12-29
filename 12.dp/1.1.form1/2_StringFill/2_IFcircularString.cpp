#include<bits/stdc++.h>
using namespace std;
//find the no. of ways to fill '?' such that no two neigh is a same char
//given its circular string

string st;
int dp[100100][4][4];

int rec(int i, int prev, int first){//0-> A ; 1->B..
    //pruning
    //base case
    if(i==st.size()){
        //u have filled all the blanks 0 to n-1 @n 
        if(first!=prev ) return 1;
        else return 0;
    }
    //cache check
    if(prev!=-1 && dp[i][prev][first]!=-1){
        return dp[i][prev][first];
    }
    //calcuate
    int ans=0;//for every level a new var ans is created
    if(st[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(ch==prev)continue;
            if(i==0){
                ans+=rec(i+1,ch,ch);
            }else{
                ans+=rec(i+1,ch,first);
            }
        }
    }else{
        if((st[i]-'A')==prev){
            return 0;
        }else{
            if(i==0){
                ans = rec(i+1,(st[i]-'A'),(st[i]-'A'));
            }else{
                ans = rec(i+1,(st[i]-'A'),first);
            }
        }
    }
    //save and return 
    if(prev!=-1)dp[i][prev][first]=ans;
    return ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>st;
    if(st.size()==1){
        if(st=="?")cout<<"4";//all possible options
        else cout<<1; //the only option A already given by question
    }else{
        cout<<rec(0,-1,-1);
    }
    
    return 0;
}

//my code

// #include<bits/stdc++.h>
// using namespace std;
// // ??AB?C??D? how many ways are there to fill ?
// //what if its circular
// int n;
// string st;
// int dp[100100][4][4];

// int rec(int i, int prev, int first){
//     //pruning 
//     //base case
//     if(i==n){
//         if(prev!=first)return 1;
//         else return 0;
//     }
//     //cache check
//     if(prev!=-1 && dp[i][prev][first]!=-1){
//         return dp[i][prev][first];
//     }
//     //calculate
//     int noWays=0;
//     if(st[i]=='?'){
//         for(int ch=0;ch<4;ch++){
//             if(ch==prev)continue;
//             if(i==0){
//                 noWays += rec(i+1,ch,ch);
//             }else{
//                 noWays += rec(i+1,ch,first);
//             }
//         }
//     }else{
//         if((st[i]-'A')!=prev){
//             if(i==0){
//                 noWays = rec(i+1,(st[i]-'A'),(st[i]-'A'));
//             }else{
//                 noWays = rec(i+1,(st[i]-'A'),first);
//             }
//         }else{
//             return 0;
//         }
//     }
//     //save and return 
//     if(prev!=-1) dp[i][prev][first]=noWays;
//     return noWays;
// }

// int main(){
//     cin>>n>>st;
//     memset(dp,-1,sizeof(dp));
//     if(n==1){
//         if(st=="?")cout<<"4\n";
//         else cout<<"0";
//     }else{
//         cout<<rec(0,-1,-1)<<"\n";
//     }
//     return 0;
// }