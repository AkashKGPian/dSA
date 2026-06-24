#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& s, int k){
        // If k is 0, no substring can have distinct characters
        if (k == 0) return 0; 
        
        int freqMap[256]={0};
        int n=s.size();

        int head=-1, tail=0;
        int ans=0;
        int dcnt=0;
        while(tail<n){
            while(head+1<n && ((freqMap[s[head+1]]==0 && dcnt<k)||
                                (freqMap[s[head+1]]!=0 && dcnt<=k) )){
                head++;
                if(freqMap[s[head]]==0) dcnt++;
                freqMap[s[head]]++;
            }
            ans=max(ans, head-tail+1);
            if(tail<=head){
                freqMap[s[tail]]--;
                if(freqMap[s[tail]]==0)dcnt--;
                tail++;
            }else{
                tail++;
                head=tail-1;
            }
        }
        return ans;
    }

    int kDistinctChar(string& s, int k) {
        // Just return the result of solve(s, k)
        // Your solve function already finds the "Longest" with "At Most K"
        return solve(s, k);
    }
};