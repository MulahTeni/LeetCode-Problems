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
    int maxLen;

    void dfs(TreeNode* r, bool b, int road){
        if(!r)   return;
        maxLen = max(maxLen, road);
        if(b){
            dfs(r->left, false, road+1);
            dfs(r->right, true, 1);
        }else{
            dfs(r->left, false, 1);
            dfs(r->right, true,  road+1);
        }
    }


    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxLen;    
    }
};