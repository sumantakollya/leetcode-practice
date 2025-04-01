#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int left = 0;
            int right = 0;
            int longest = 0;
            int max_freq = 0;
            unordered_map<char, int> hmap;
    
            while (right < s.size()) {
    
                //cout<<"insert "<<s[right]<<endl;
                hmap[s[right]] += 1;
    
                max_freq = max(max_freq, hmap[s[right]]);
                //cout<<"max-freq "<<max_freq<<endl;
    
                //cout<<"left "<<left<<" right "<<right<<endl;
                while (right - left + 1 > max_freq + k) {
                    //cout<<"remove "<<s[left]<<endl;
                    hmap[s[left]] -= 1;
                    left++;
                }
            
                longest = max(longest,right - left + 1);
                //cout<<"longest "<<longest<<endl;
                right++;
            }
    
            return longest;
        }
    };