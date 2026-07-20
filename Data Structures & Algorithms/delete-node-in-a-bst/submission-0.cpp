class Solution {
private:
    TreeNode* findmin(TreeNode* root) {
        // Keep moving left to find the smallest node
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Step 1: Search for the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // Step 2: Node found, handle deletion cases
        else { 
            // Case 1 & 2: Leaf node or node with only one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node with two children
            // Find the inorder successor (smallest in the right subtree)
            TreeNode* successor = findmin(root->right);
            
            // Replace current value with successor value
            root->val = successor->val;
            
            // Delete the duplicate successor node from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};
