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

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        bool toright = false;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!node) {
                ans.push_back(level);
                level.clear();
                if(!q.empty()) q.push(nullptr);
                toright = !toright;
                continue;
            }

            level.push_back(node->val);

            if(toright) {
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }else {
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }

        return ans;
    }
};