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
    int findDepth(TreeNode* root) {
        if(!root) return 0;

        return 1+findDepth(root->left);
    }

    int findMinus(TreeNode* root, int depth, int level) {    
        if(level == depth-1) {
            if(!root->left) return 2;
            if(!root->right) return 1;
            return 0;
        }

        int count = findMinus(root->right, depth, level+1);
        
        if(count == (depth-level-1)*2) {
            return count + findMinus(root->left, depth, level+1);
        }

        return count;
    }

    int countNodes(TreeNode* root) {
        int depth = findDepth(root);

        if(depth < 2) {
            if(!root) return 0;
            if(!root->left) return 1;
            if(!root->right) return 2;
            return 3;
        }

        int minus = findMinus(root, depth, 1);

        int nodeif = 1;

        while(depth > 0) {
            nodeif *= 2;
            depth--;
        }

        nodeif--;

        return nodeif-minus;
    }
};