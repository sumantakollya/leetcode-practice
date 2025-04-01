#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<pair<int,int>> car(position.size());
            stack<double> times;
            int fleet=0;
            double curr_time=0;
        
            for (int i=0;i<position.size();i++) {
                car[i] = {position[i],speed[i]};
            }
    
            sort(car.begin(),car.end());
    
            for (int i=0;i<position.size();i++) {
                double t = (double)(target - car[i].first)/car[i].second;
                times.push(t);
            }
    
            while(!times.empty()) {
                if (times.top() <= curr_time)
                    times.pop();
                else {
                    curr_time = times.top();
                    times.pop();
                    fleet++;
                }
            }
    
            return fleet;
        }
    };