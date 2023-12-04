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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val<key){                              //  bst search
            root->right = deleteNode(root->right, key); //
        }else if(root->val>key){                        //
            root->left = deleteNode(root->left, key);   //
        }else{
            if(!root->left && !root->right){            // 0 child
                delete(root);
                return NULL;
            }
            if(!root->left || !root->right){            // 1 child
                TreeNode* tmp = root->left ? root->left : root->right;
                delete(root);
                return tmp;
            }
            if(root->left && root->right){              // 2 child
                TreeNode* suc = root->right;
                while(suc->left)    suc = suc->left;
                root->val = suc->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};