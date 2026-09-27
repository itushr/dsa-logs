/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* parent) {
        if (!root) return nullptr;

        TreeNode* lhs = lca(root->left, p, q, root);
        TreeNode* rhs = lca(root->right, p, q, root);

        if (!lhs || !rhs) {
            if (root == p || root == q) {
                if (lhs || rhs) return root;
                else return parent;
            }

            if (lhs) return lhs;
            return rhs;
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q, nullptr);
    }
};