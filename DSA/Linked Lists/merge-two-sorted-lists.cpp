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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* itr1 = list1;
            ListNode* itr2 = list2;
            ListNode* result;
            ListNode* curr;
    
            result = curr = new ListNode();
    
            while (itr1 != NULL && itr2 != NULL){
                if (itr1->val < itr2->val)
                {
                    curr->next = itr1;
                    curr = curr->next;
    
                    itr1 = itr1->next;
                } 
                else 
                {
                    curr->next = itr2;
                    curr = curr->next;
    
                    itr2 = itr2->next;
                }
            }
    
            while (itr1 != NULL)
            {
                curr->next = itr1;
                curr = curr->next;
                itr1 = itr1->next;
            }
    
            while (itr2 != NULL)
            {
                curr->next = itr2;
                curr = curr->next;
                itr2 = itr2->next;
            }
    
            return result->next;
        }
    };