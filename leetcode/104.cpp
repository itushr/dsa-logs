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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q; 

        q.push(root);
        q.push(nullptr);

        int ans = 0;

        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if(top == nullptr) {
                ans++;
                if(!q.empty()) {
                    q.push(nullptr);
                }
                continue;
            }

            if(top->left) {
                q.push(top->left);
            }

            if(top->right) {
                q.push(top->right);
            }
        }

        return ans;
    }
};