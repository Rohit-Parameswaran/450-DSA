class Solution{
    vector<int> inOrder;
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void getInorder(Node* root) {
        if(!root) return;
        getInorder(root->left);
        inOrder.push_back(root->data);
        getInorder(root->right);
    }
    
    void reconstruct(Node *root, int &i) {
        if(!root) return;
        reconstruct(root->left, i);
        root->data = inOrder[i++];
        reconstruct(root->right, i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        getInorder(root);
        sort(inOrder.begin(), inOrder.end());
        int i=0;
        reconstruct(root, i);
        return root;
    }
};