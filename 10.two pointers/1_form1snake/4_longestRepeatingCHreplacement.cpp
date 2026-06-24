#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(256, 0);
        int maxCount = 0; // Frequency of the most common character in the current window

        int head = 0;
        int ans = 0;
        
        for (int tail = 0; tail < s.size(); tail++) {
            // Update frequency of the current character
            count[s[tail]]++;
            // Update the max frequency found so far in the window
            maxCount = max(maxCount, count[s[tail]]);
            
            // If (window size - max frequency) > k, the window is invalid
            while ((tail - head + 1) - maxCount > k) {
                count[s[head]]--;
                head++;
                // Note: We don't strictly need to update maxCount here 
                // because a smaller maxCount won't help us find a better ans
            }
            
            ans = max(ans, tail - head + 1);
        }
        
        return ans;
    }
};