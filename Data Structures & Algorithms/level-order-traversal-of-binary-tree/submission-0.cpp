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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue <TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        //queue FIFO means root added first going to cur node pop it and then push 
        // it in res
        while(!q.empty()){
            int levelsize = q.size(); //for first level its 1 then level 2 its 2 cuz added left and right of root (if any)
            vector<int> currentlevel;
            for(int i=0;i<levelsize;i++){
              TreeNode* curr = q.front(); //save it before deleting
               q.pop(); //pop it from front
               currentlevel.push_back(curr->val); // adding val of it current level vactor 
              if(curr->left) q.push(curr->left);
              if(curr->right) q.push(curr->right);
            }
            res.push_back(currentlevel);
        }
        return res;
    }
};
