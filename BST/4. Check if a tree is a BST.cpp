//Question Link - https://practice.geeksforgeeks.org/problems/check-for-bst/1

class Solution
{
    Node *pre = NULL;
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        if(!root) return true;
        //checking if left subtree is a BST
        if(!isBST(root->left)) return false;

        // For a BST, inorder traversal is a sorted array. 
        // Inorder predecessor should be lesser than the current node
        if(pre && pre->data >= root->data) return false;
        pre = root;

        // checking if right subtree is a BST
        if(!isBST(root->right)) return false;
        return true;
    }
};