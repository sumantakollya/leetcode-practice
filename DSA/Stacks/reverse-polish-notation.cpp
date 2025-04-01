#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            
            stack<int> stk;
            int a,b,tmp;
            for (auto &it : tokens) {
                if (it=="+"){
                    b = stk.top();
                    stk.pop();
                    a = stk.top();
                    stk.pop();
                    tmp = a+b;
                    stk.push(tmp);
                }
                else if (it == "-") {
                    b = stk.top();
                    stk.pop();
                    a = stk.top();
                    stk.pop();
                    tmp = a-b;
                    stk.push(tmp);
                }
                else if (it == "*") { 
                    b = stk.top();
                    stk.pop();
                    a = stk.top();
                    stk.pop();
                    tmp = a*b;
                    stk.push(tmp);
                }
                else if (it == "/") {
                    b = stk.top();
                    stk.pop();
                    a = stk.top();
                    stk.pop();
                    tmp = a/b;
                    stk.push(tmp);
                }
                else {
                    stk.push(stoi(it));
                }
            }
    
            return stk.top();
        }
    };