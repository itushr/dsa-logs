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
    TreeNode* build(span<int> preorder, span<int> inorder) {
        int n = preorder.size();
        
        TreeNode* root = new TreeNode(preorder[0]);

        int lhslen = 0;
        while(inorder[lhslen] != preorder[0]) lhslen++;

        if(lhslen > 0) {
            span<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + lhslen);
            span<int> leftInorder(inorder.begin(), inorder.begin() + lhslen);
            root->left = build(leftPreorder, leftInorder);
        }

        if(n-lhslen-1 > 0) {
            span<int> rightPreorder(preorder.begin() + 1 + lhslen, preorder.end());
            span<int> rightInorder(inorder.begin() + lhslen + 1, inorder.end());
            root->right = build(rightPreorder, rightInorder);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;

        span<int> preorderSpan(preorder.begin(), preorder.end());
        span<int> inorderSpan(inorder.begin(), inorder.end());

        return build(preorderSpan, inorderSpan);
    }
};