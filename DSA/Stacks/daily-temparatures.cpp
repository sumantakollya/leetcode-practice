#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temp) {
            vector<int> answer(temp.size());
            stack<pair<int,int>> stk;
    
            for (int i=0;i<temp.size();i++) {
                if (!stk.empty() && stk.top().first < temp[i]) {
                    int j;
                    while(!stk.empty() && stk.top().first < temp[i]) {
                        j=stk.top().second;
                        //cout<<"poping "<<stk.top().first<<" "<<stk.top().second<<endl;
                        stk.pop();
                        answer[j] = i-j;
                    }
                    //cout<<"then pushing "<<temp[i]<<" "<<i<<endl;
                    stk.push({temp[i],i});
                }
                else {
                    //cout<<"pushing "<<temp[i]<<" "<<i<<endl;
                    stk.push({temp[i],i});
                }
            }
    
            return answer;
    
        }
    };