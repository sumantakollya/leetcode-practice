#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>> hmap;
            vector<vector<string>> res;
            
            for (auto it = strs.begin(); it != strs.end(); it++) {
                string temp = *it;
                sort(temp.begin(),temp.end());
    
                hmap[temp].push_back(*it);
            }
    
            for (auto it=hmap.begin();it != hmap.end(); it++) {
                res.push_back(it->second);
            }
    
            return res;
        }
    };