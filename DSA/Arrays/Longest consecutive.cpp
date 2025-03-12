#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            
            set<long> hmap;
            if (nums.size() == 0)
                return 0;
            for (int i=0;i< nums.size();i++) {
                hmap.insert(nums[i]);
            }
    
            int max_seq = 0;
            int curr_seq = 0;
            long prev = LONG_MIN;
            for (auto it = hmap.begin(); it!= hmap.end();it++) {
                //cout<<it->first<<" "<<it->second<<endl;
                //cout<<"compare "<<it->first<<" "<<prev+1<<endl;
                if (*it != prev + 1) {
                    max_seq = max(curr_seq,max_seq);
                    curr_seq = 0;
                } else {
                    curr_seq++;
                }
                prev = *it;
            }
            max_seq = max(curr_seq,max_seq);
            return max_seq+1;
        }
    };