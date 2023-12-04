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
    int sum, depth=INT_MIN;
    void dfs(TreeNode* root, int currDepth){
        if(!root)   return;
        if(!root->left && !root->right){
            if(depth==currDepth)    sum += root->val;
            else if(depth<currDepth){
                sum = root->val;
                depth = currDepth;
            }
            return;
        }
        dfs(root->left, currDepth+1);
        dfs(root->right, currDepth+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 1);
        return sum;
    }
};