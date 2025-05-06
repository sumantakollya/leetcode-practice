/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        bool balanced = true;
        int traverse(TreeNode *root)
        {
            if (root == nullptr)
                return 0;
            
            int lheight = traverse(root->left);
            int rheight = traverse(root->right);
    
            if (lheight > rheight + 1){
                balanced = false;
                //cout<<lheight<<" "<<rheight<<endl;
            }
                
            if (rheight > lheight + 1)
            {
                balanced = false;
                //cout<<lheight<<" "<<rheight<<endl;
            }
    
            return max(1+lheight, 1+rheight);
        }
        bool isBalanced(TreeNode* root) {
    
            traverse(root);
            return balanced;
        }
    };