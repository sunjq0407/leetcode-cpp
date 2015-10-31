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
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        if(!root->left&&!root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        else {
            if(root->left) helper(root->left, to_string(root->val));
            if(root->right) helper(root->right, to_string(root->val));
            return result;
        }
    }
    void helper(TreeNode* node, string str) {
        if(!node->left&&!node->right) {
            str += "->" + to_string(node->val);
            result.push_back(str);
            return;
        }
        else {
            str += "->" + to_string(node->val);
            if(node->left) helper(node->left, str);
            if(node->right) helper(node->right, str);
        }
    }
};