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
    bool isSameTree(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;

        if(!a || !b || a->val != b->val) return false;

        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if sub root is end then subroot is part of root
        if(!subRoot) return true;
        //root end but subroot is still so false
        if(!root) return false;

        if(isSameTree(root,subRoot)){
            return true; //if subtree is same then return true
        }
        //check left and right nodes recursively
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
