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
    pair<int, int> duck(TreeNode* root) {
        if(!root) return {0, 0};

        auto [leftlen, maxleftlen] = duck(root->left);
        auto [rightlen, maxrightlen] = duck(root->right);

        int maxside = max(maxleftlen, maxrightlen);

        return {max(leftlen, rightlen)+1, max(maxside, leftlen+rightlen)};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return duck(root).second;
    }
};