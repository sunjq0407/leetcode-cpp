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
    int countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while(left&&right) {
            left = left->left;
            right = right->right;
            depth++;
        }
        if(!left&&!right) return (1<<depth) - 1;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};