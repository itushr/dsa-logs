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
    int duck(TreeNode* root, int num) {
        if(!root->left && !root->right) return num*10+root->val;
        
        int sum = 0;

        if(root->left) sum += duck(root->left, num*10+root->val);
        if(root->right) sum += duck(root->right, num*10+root->val);

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return duck(root, 0);
    }
};