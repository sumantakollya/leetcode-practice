#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0;
            int right = 0;
    
            int len=0,maxlen=0;
    
            unordered_map<char,int> dupli_map;
    
            while (left <= right && right < s.size()) {
                char curr_c = s[right];
    
                if (dupli_map[curr_c] > 0) {
                    char left_c = s[left];
                    dupli_map[left_c] -= 1;
                    len--;
                    left++;
                }
                else {
                    dupli_map[curr_c] += 1;
                    len++;
                    right++;
                }
    
                if (len > maxlen)
                    maxlen = len;
            }
    
            return maxlen;
        }
    };