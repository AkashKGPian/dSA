#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ansHead = -1, ansTail = -1;
    int minLen = 1e9;

    void solve(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        int i = 0; // Pointer for s1
        int j = 0; // Pointer for s2

        while (i < n) {
            // 1. Expand i (forward pass) until s2 is a subsequence
            if (s1[i] == s2[j]) {
                j++;
            }
            
            // 2. If j reaches m, we found a valid window ending at i
            if (j == m) {
                int head = i;
                int tempJ = m - 1;
                int tail = i;

                // 3. Reverse pass: Shrink from the end to find the optimal start
                while (tempJ >= 0) {
                    if (s1[tail] == s2[tempJ]) {
                        tempJ--;
                    }
                    if (tempJ >= 0) tail--;
                }

                // 4. Update minLen and answer pointers
                if (head - tail + 1 < minLen) {
                    minLen = head - tail + 1;
                    ansHead = head;
                    ansTail = tail;
                }
                
                // 5. Reset: Start looking for the next window from the character 
                // right after the start of our current best window
                i = tail + 1;
                j = 0;
            } else {
                i++;
            }
        }
    }

    string minWindow(string s1, string s2) {
        ansHead = -1; ansTail = -1;
        minLen = 1e9;

        solve(s1, s2);

        if (ansHead == -1) return "";
        return s1.substr(ansTail, ansHead - ansTail + 1);
    }
};