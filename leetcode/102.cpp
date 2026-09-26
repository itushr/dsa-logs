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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> row;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(!front) {
                ans.push_back(row);
                row.clear();
                if(!q.empty()) {
                    q.push(nullptr);
                }
                continue;
            }

            row.push_back(front->val);

            if(front->left) {
                q.push(front->left);
            }

            if(front->right) {
                q.push(front->right);
            }
        }

        return ans;
    }
};