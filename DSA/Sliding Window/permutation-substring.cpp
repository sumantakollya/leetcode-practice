#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            array<int, 26> hmap1;
            array<int, 26> hmap2;
            int len = s1.size();
    
            if (s2.size() < len)
                return false;
    
            for (int i=0; i< len; i++) {
                hmap1[s1[i]-'a']++;
                hmap2[s2[i]-'a']++;
            }
    
            for (int i=0; i+len< s2.size(); i++) {
                if (hmap1 == hmap2) {
                    return true;
                } else {
                    hmap2[s2[i]-'a']--;
                    hmap2[s2[i+len]-'a']++;
                }
            }
    
            if (hmap1 == hmap2)
                return true;
    
            return false;
        }
    };