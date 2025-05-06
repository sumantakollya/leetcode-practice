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
        bool hasCycle(ListNode *head) {
    
            if (head == NULL)
                return false;
    
            ListNode *slow = head;
            ListNode *fast = head->next;
    
            while (slow != NULL && fast != NULL)
            {
                if (fast->next == slow)
                    return true;
                
                slow = slow->next;
                if (fast->next)
                    fast = fast->next->next;
            }
    
            return false;
        }
    };