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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;

        if(!root) return ans;

        stack<TreeNode*> prev;
        stack<TreeNode*> curr;

        prev.push(root);

        bool ltr = true;

        while(!prev.empty()) {
            while(!prev.empty()) {
                TreeNode* node = prev.top();
                if(ltr) {
                    if(node->left) curr.push(node->left);
                    if(node->right) curr.push(node->right);
                }else {
                    if(node->right) curr.push(node->right);  
                    if(node->left) curr.push(node->left);
                }
                level.push_back(node->val);
                prev.pop();
            }

            ans.push_back(level);
            level = {};
            ltr = !ltr;
            swap(prev, curr);
        }

        return ans;
    }
};