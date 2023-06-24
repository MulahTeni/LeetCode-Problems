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
    vector<int> res;
    int depth=INT_MIN;
    void dfs(TreeNode* root, int currDepth){
        if(!root)   return;
        if(depth<currDepth){
            res.push_back(root->val);
            depth = currDepth;
        }
        dfs(root->right, currDepth+1);
        dfs(root->left, currDepth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};