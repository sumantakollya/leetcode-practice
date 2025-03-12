#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            int left,right;
    
            for (int i=0;i<nums.size();i++)
            {
                left = i+1;
                right = nums.size()-1;
    
                if (i > 0 && nums[i]==nums[i-1])
                    continue;
    
                while(left < right) {
    
                    int sum = nums[i]+nums[left]+nums[right];
    
                    if (sum > 0)
                        right--;
                    else if(sum < 0)
                        left++;
                    else {
                        result.push_back({nums[i],nums[left],nums[right]});
                        //cout<<"i "<<i<<" left "<<left<<" right "<<right<<endl;
                        while (left < right) {
                            if (nums[left]==nums[left+1])
                                left++;
                            else
                                break;
                        }
    
                        while (right > left) {
                            if (nums[right]==nums[right-1])
                                right--;
                            else
                                break;
                        }
    
                        left++;
                        right--;
                    }
                }
            }
    
            return result;
        }
    };