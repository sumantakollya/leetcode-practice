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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *itr1 = l1;
            ListNode *itr2 = l2;
            ListNode *result = new ListNode();
            ListNode *curr = result;
            
            int carry = 0;
            int sum = 0;
    
            while (itr1 != NULL && itr2 != NULL)
            {
                sum = itr1->val+itr2->val+carry;
                carry = sum/10;
    
                curr->next = new ListNode(sum%10);
                curr = curr->next;
    
                itr1 = itr1->next;
                itr2 = itr2->next;
            }
    
            while(itr1 != NULL)
            {
                sum = itr1->val+carry;
                carry = sum/10;
                curr->next = new ListNode(sum%10);
                curr = curr->next;
                itr1 = itr1->next;
            }
    
            while(itr2 != NULL)
            {
                sum = itr2->val+carry;
                carry = sum/10;
                curr->next = new ListNode(sum%10);
                curr = curr->next;
                itr2 = itr2->next;
            }
    
            if (carry != 0)
            {
                curr->next = new ListNode(carry);
                curr = curr->next;
            }
    
            return result->next;
        }
    };