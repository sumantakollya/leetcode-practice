#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            
            int bitr=0;
            int eitr=nums.size()-1;
            int stepsum=0;
            vector<int> result = {0,0};
    
            while(bitr < eitr) {
                stepsum = nums[bitr] + nums[eitr];
                //cout<<bitr<<" "<<eitr<<" "<<stepsum<<endl;
                if (stepsum == target) {
                    result = {bitr+1,eitr+1};
                    break;
                }
                else if (stepsum < target)
                    bitr++;
                else
                    eitr--;
            }
    
            return result;
        }
    };