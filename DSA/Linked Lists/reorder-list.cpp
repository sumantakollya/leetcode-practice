#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        void reorderList(ListNode* head) {
            stack<ListNode*> stk;
            ListNode *itr = head;
            ListNode *tmp = NULL;
            ListNode *next = NULL;
    
            while (itr != NULL)
            {
                stk.push(itr);
                itr = itr->next;
            }
    
            int list_len = stk.size();
            itr = head;
    
            for (int i=0; i < list_len/2; i++)
            {
                tmp = stk.top();stk.pop();
    
                next = itr->next;
    
                itr->next = tmp;
                tmp->next = next;
    
                itr = next;
            }
    
            itr->next = NULL;
    
        }
    };