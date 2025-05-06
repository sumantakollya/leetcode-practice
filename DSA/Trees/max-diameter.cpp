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
        int max_dia = INT_MIN;
        int dia(TreeNode *root) {
            
            if (root == nullptr)
                return 0;
            
            int lheight = dia(root->left);
            int rheight = dia(root->right);
            
            max_dia = max(max_dia, lheight+rheight);
            
            return max(lheight + 1, rheight + 1);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            dia(root);
            return max_dia;
        }
    };