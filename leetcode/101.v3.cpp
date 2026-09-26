/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* x, TreeNode* y) {
        if (!x->left || !y->right) {
            if (x->left)
                return false;
            if (y->right)
                return false;
        }

        if (!y->left || !x->right) {
            if (y->left)
                return false;
            if (x->right)
                return false;
        }

        bool isleftmirror = true;
        bool isrightmirror = true;

        if (x->left) {
            if (x->left->val != y->right->val) {
                return false;
            }
            isleftmirror = isMirror(x->left, y->right);
        }

        if (y->left) {
            if (y->left->val != x->right->val) {
                return false;
            }
            isrightmirror = isMirror(x->right, y->left);
        }

        return isleftmirror && isrightmirror;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left || !root->right) {
            if (root->left)
                return false;
            if (root->right)
                return false;
            return true;
        }

        if (root->left->val != root->right->val) {
            return false;
        }

        return isMirror(root->left, root->right);
    }
};