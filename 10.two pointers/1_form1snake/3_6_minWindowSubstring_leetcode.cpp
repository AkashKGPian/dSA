#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int freqMap[256] = {0};
    int cnt = 0; // Total required characters (length of t)
    int ansHead = -1, ansTail = -1;

    void solve(string& s) {
        int n = s.size();
        int foundTill[256] = {0};

        int head = -1, tail = 0;
        int minLen = 1e9;
        int dcnt = 0; // Current count of required characters satisfied

        while (tail < n) {
            // 1. Expand head until window is valid
            while (head + 1 < n && dcnt < cnt) {
                head++;
                if (foundTill[s[head]] < freqMap[s[head]]) {
                    dcnt++;
                }
                foundTill[s[head]]++;
            }

            // 2. If window is valid, update the minimum length
            if (dcnt == cnt) {
                if (head - tail + 1 < minLen) {
                    minLen = head - tail + 1;
                    ansHead = head;
                    ansTail = tail;
                }
            }

            // 3. Move tail forward to shrink window
            if (tail <= head) {
                if (foundTill[s[tail]] <= freqMap[s[tail]]) {
                    dcnt--;
                }
                foundTill[s[tail]]--;
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }
    }

    string minWindow(string s, string t) {
        // Reset global/member variables for fresh test cases
        for(int i=0; i<256; i++) freqMap[i] = 0;
        cnt = t.size();
        ansHead = -1; ansTail = -1;

        for (char c : t) freqMap[c]++;

        solve(s);

        if (ansHead == -1) return "";
        
        // Correct way to extract substring: s.substr(start_index, length)
        return s.substr(ansTail, ansHead - ansTail + 1);
    }
};