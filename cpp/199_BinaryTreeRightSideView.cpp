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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* tmp=NULL;
            while(n--){
                tmp = q.front();
                q.pop();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
            res.push_back(tmp->val);
        }
        return res;
    }
}
 
 
 
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