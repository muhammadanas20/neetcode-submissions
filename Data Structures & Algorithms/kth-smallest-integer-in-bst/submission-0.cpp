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
    //by using arr then traverse through inorde travel due to BST gives the sorted array
     // BST -> left < root < right
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root,arr);
        return arr[k-1]; //kth is the position if smallest value return 
    }
    void dfs(TreeNode* root,vector<int>& arr){
        if(!root) return;

        dfs(root->left,arr); //first do left cuz it smaller
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
};
