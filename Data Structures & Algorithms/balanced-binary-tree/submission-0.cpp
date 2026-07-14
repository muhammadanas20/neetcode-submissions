class Solution {
private:
    // Returns the height of the tree if balanced, or -1 if unbalanced
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        
        // Check if left subtree is balanced
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;
        
        // Check if right subtree is balanced
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return actual height of current node
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
