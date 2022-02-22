//Question Link - https://leetcode.com/problems/delete-node-in-a-bst/
//Question Link - https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1#

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    
    //Traverse left subtree
    if(key < root->val) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    
    //Traverse right subtree
    else if(key > root->val) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    
    //At node to be deleted
    //Deleting a leaf node 
    if(!root->left && !root->right) {
        delete root;
        return NULL;
    }
    //Deleting a node with one child
    else if(!root->left || !root->right) {
        TreeNode *temp = root->left ? root->left : root->right;
        delete root;
        return temp;
    }
    //Deleting a node with two children
    TreeNode *pre = root->left;
    while(pre->right) pre = pre->right;
    root->val = pre->val;
    root->left = deleteNode(root->left, pre->val);
    return root;
}