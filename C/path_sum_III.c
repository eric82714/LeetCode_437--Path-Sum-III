/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
    
int pathSumToRoot(struct TreeNode* root, int sum) {
    if (!root) return 0;
        
    int result = 0;
    result += pathSumToRoot(root->left, sum - root->val);
    result += pathSumToRoot(root->right, sum - root->val);
    
    if(root->val == sum) result++;
        
    return result;
}

int pathSum(struct TreeNode* root, int sum){
    if (!root) return 0;
        
    int result = pathSum(root->left, sum) + pathSum(root->right, sum);
    result += pathSumToRoot(root->left, sum - root->val);
    result += pathSumToRoot(root->right, sum - root->val);
        
    if(root->val == sum) result++;
        
    return result;
}
