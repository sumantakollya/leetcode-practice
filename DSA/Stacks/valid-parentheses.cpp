#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
    
        stack<char> buff;
        
        for (auto &it : s) {
            if (it=='(' || it=='[' || it=='{'){
                buff.push(it);
            }
            else {
                if (buff.empty())
                    goto invalid;
                switch (it) {
                    case ')':
                        if (buff.top()=='(')
                            buff.pop();
                        else
                            goto invalid;
                        break;
                    case ']':
                        if (buff.top()=='[')
                            buff.pop();
                        else
                            goto invalid;
                        break;
                    case '}':
                        if (buff.top()=='{')
                            buff.pop();
                        else
                            goto invalid;
                        break;
                }
            }
        }
        
        return buff.empty();
        invalid:
            return false;
        }
    };