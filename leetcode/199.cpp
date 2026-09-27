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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!node) {
                if(!q.empty()) q.push(nullptr);
                continue;
            }

            if(q.front() == nullptr) {
                ans.push_back(node->val);
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return ans;
    }
};