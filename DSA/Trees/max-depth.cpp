
#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            int l,r;
    
            if (root == nullptr)
                return 0;
    
            l = maxDepth(root->left);
            r = maxDepth(root->right);
    
            return max(l+1,r+1);
        }
};