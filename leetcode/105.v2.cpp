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
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder, int& prei, int inleft,
                    int inright) {
        if (inleft > inright)
            return nullptr;

        int value = preorder[prei++];
        TreeNode* root = new TreeNode(value);

        int mid = pos[value];

        root->left = build(preorder, prei, inleft, mid - 1);

        root->right = build(preorder, prei, mid + 1, inright);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        int prei = 0;

        return build(preorder, prei, 0, inorder.size() - 1);
    }
};