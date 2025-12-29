#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>s;
    n=s.length();
    
    int dp[n+1];
    int prefix[n+1];
    int lastt[26];
    memset(lastt,-1,sizeof(lastt));
    
    dp[0]=1;//unique subseq ending at i-1 of string
    prefix[0]=1;//sum of dp[0,...i]
    for(int i=1;i<=n;i++){
        //add after all character
        dp[i]=prefix[i-1];
        if(lastt[s[i-1]-'a']!=-1){
            //remove the extra that got added ie removing the duplicates
            int idx = lastt[s[i-1]-'a'];
            dp[i]-=prefix[idx];
        }
        //update this as the last index  where this char is present
        lastt[s[i-1]-'a']=i-1;
        // build the prefix array
        prefix[i]=prefix[i-1]+dp[i];
    }
    cout<<prefix[n]-1<<"\n";
    return 0;
}
