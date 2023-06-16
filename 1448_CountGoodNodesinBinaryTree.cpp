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
    void dfs(TreeNode* root, int& res, int val){
        if(root==NULL)  return;
        if(root->val>=val)   ++res;
        val = max(val, root->val);
        dfs(root->right, res, val);
        dfs(root->left, res, val);
    }
    int goodNodes(TreeNode* root) {
        int res=0;
        dfs(root, res, root->val);
        return res;
    }
};