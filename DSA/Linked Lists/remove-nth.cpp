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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* itr = head;
            ListNode* prev = NULL;
            int list_len = 0;
    
            while (itr != NULL)
            {
                list_len++;
                itr = itr->next;
            }
    
            itr = head;
    
            for (int i=0; i < list_len-n; i++)
            {
                prev = itr;
                itr = itr->next;
            }
    
            if (list_len == 1)
                return NULL;
            if (prev == NULL)
                return itr->next;
            else
                prev->next = itr->next;
            return head;
        }
    };