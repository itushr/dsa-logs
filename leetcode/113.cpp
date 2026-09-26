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
    void duck(TreeNode* root, int targetSum, int pathSum, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(root->val);
        pathSum += root->val;

        if(!root->left && !root->right) {
            if(pathSum == targetSum) {
                ans.push_back(path);
            }
        } else {
            if(root->left) {
                duck(root->left, targetSum, pathSum, path, ans);
            }
            if(root->right) {
                duck(root->right, targetSum, pathSum, path, ans);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;
        
        if(!root) return ans;

        duck(root, targetSum, 0, path, ans);
        return ans;
    }
};