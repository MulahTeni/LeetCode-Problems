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
    TreeNode* searchBST(TreeNode* root, int val) {
        return bstSearch(root, val);
        return dfs(root, val);
        return bfs(root, val);
    }

    TreeNode* bstSearch(TreeNode* root, int val){
        if(!root)   return NULL;
        if(val==root->val)  return root;
        if(val>root->val)   return bstSearch(root->right, val);
        if(val<root->val)   return bstSearch(root->left, val);
        return NULL;
    }

    TreeNode* dfs(TreeNode* root, int val){
        if(!root)   return NULL;
        if(root->val == val)    return root;
        TreeNode* left = dfs(root->left, val);
        TreeNode* right = dfs(root->right, val);
        return left ? left : right ? right : NULL;
    }

    TreeNode* bfs(TreeNode* root, int val){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->val == val) return tmp;
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
        }
        return NULL;
    }
};