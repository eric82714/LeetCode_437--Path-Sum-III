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
    int counts = 0;
    
    void helper(TreeNode* root, int sum) {
        if(!root) return;
        if(root->val == sum) counts++;
        helper(root->left, sum-root->val);
        helper(root->right, sum-root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root) {
            helper(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return counts;
    }
};
