class Solution {
public:
    string st,s;
    int dp[1001][1001];
    int rec(int l, int r){
        //base case
        if(l>r) return 0;
        if(l==r) return 1;
        //cache check
        if(dp[l][r]!=-1) return dp[l][r];
        //transtitions
        int ans=0;
        if(s[l]==s[r])
            ans=2+rec(l+1,r-1);
        else if(rec(l+1,r)>rec(l,r-1))
            ans=rec(l+1,r);
        else 
            ans=rec(l,r-1);
        //save and return
        return dp[l][r]=ans;
    }
    
    void generate(int l, int r){
        if(l>r) return ;
        if(l==r){
            st+=s[l];
            return;
        }
        if(s[l]==s[r]){
            st+=s[l];
            generate(l+1,r-1);
            st+=s[r];
        }
        else if(dp[l+1][r] > dp[l][r-1])
            generate(l+1,r);
        else
            generate(l,r-1);
    }
    string longestPalindrome(string input_s) {
        s=input_s;
        memset(dp,-1,sizeof(dp));

        int sz=s.size();
        int rc = rec(0,sz-1);
        generate(0,sz-1);

        return st;
    }   
};