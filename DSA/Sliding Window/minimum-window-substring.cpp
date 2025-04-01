#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool valid_substr(map<char,int> &tmap, map<char,int> &smap) {
            for (auto it : tmap) {
                if (smap[it.first] < it.second)
                    return false;
            }
            return true;
        }
    
        string minWindow(string s, string t) {
            int len = t.size();
            map<char, int> tmap;
            map<char, int> smap;
            pair<int,int> min_win;
    
            min_win.first = 0;
            min_win.second = INT_MAX;
    
            for (int i=0; i < len; i++) {
                tmap[t[i]] += 1;
                smap[s[i]] += 1;
            }
    
            int left = 0;
            int right = len;
    
            while (right < s.size()) {
                if (valid_substr(tmap, smap)) {
                    //shrink the window
                    //cout<<"valid sub string "<<left<<" "<<right<<endl;
                    if (right - left < min_win.second - min_win.first)
                    {
                        min_win.second = right;
                        min_win.first = left;
                    }
                    smap[s[left]] -= 1;
                    left += 1;
                } else {
                    //increase the window
                    //cout<<"not valid sub string "<<left<<" "<<right<<endl;
                    smap[s[right]] += 1;
                    right += 1;
                }
            }
    
            //last window
            while (right >= left+len-1) {
                if (valid_substr(tmap, smap)) {
                    //cout<<"valid sub strings "<<left<<" "<<right<<endl;
                    if (right-left < min_win.second-min_win.first)
                    {
                        min_win.first = left;
                        min_win.second = right;
                    }
                    smap[s[left]] -= 1;
                    left += 1;   
                }
                else
                    break;
            }
    
            //cout<<"substring "<<min_win.first<<" "<<min_win.second<<endl;
            if (min_win.second != INT_MAX)
                return s.substr(min_win.first, min_win.second - min_win.first);
            else
                return "";
        }
    };