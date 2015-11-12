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
    int ans = 0;
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
    void helper(TreeNode* root, int k){
        if(count>k || !root) return;
        helper(root->left, k);
        if(++count == k) {
            ans = root->val;
            return;
        }
        helper(root->right,k);
    }
};