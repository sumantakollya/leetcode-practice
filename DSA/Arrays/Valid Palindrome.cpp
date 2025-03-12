#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string c_str;
    
            for (auto ch : s) {
                if (isalnum(ch))
                    c_str += tolower(ch);
            }
    
            int bitr=0;
            int eitr=c_str.size()-1;
    
            while (bitr < eitr) {
                if (c_str[bitr] != c_str[eitr])
                    return false;
                bitr++;
                eitr--;
            }
    
            return true;
        }
    };