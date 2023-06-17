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
    int count;

    void dfs(TreeNode* root, long tSum){
        if(!root)   return;
        if(root->val==tSum) ++count;
        if(root->right) dfs(root->right, tSum - root->val);
        if(root->left) dfs(root->left, tSum - root->val);
    }


    int pathSum(TreeNode* root, long tSum) {
        if(root){
            dfs(root, tSum);
            pathSum(root->left, tSum);
            pathSum(root->right, tSum);
        }

        return count;
    }
};