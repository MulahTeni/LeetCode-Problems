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
    int maxLevelSum(TreeNode* root) {
        if(!root)   return 0;
        queue<TreeNode*> q;
        vector<int> sums;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)   q.push(tmp->right);
            }
            sums.push_back(sum);
        }
        int res = 0;
        int maxSum = INT_MIN;
        for(int i=0; i<sums.size(); ++i){
            if(sums[i]>maxSum){
                res = i;
                maxSum = sums[i];
            }
        }
        return ++res;
    }
};