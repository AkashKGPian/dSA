#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (centered on a character)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (centered between two characters)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            // If we found a longer palindrome, update the starting index and max length
            if (len > maxLen) {
                maxLen = len;
                // Calculate the starting index of the substring
                start = i - (len - 1) / 2; 
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        // Expand outward while within bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // The length of the palindrome is (right - left - 1) 
        // because the loop breaks when s[left] != s[right]
        return right - left - 1;
    }
};