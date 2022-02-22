
void getInorder(Node* root, vector<Node*> &inorder) {
    if(!root) return;
    getInorder(root->left, inorder);
    inorder.push_back(root);
    getInorder(root->right, inorder);
}

Node* getBst(vector<Node*> &inorder, int l, int r) {
    if(l == r) {
        inorder[l]->left = inorder[l]->right = NULL; 
        return inorder[l];
    }
    if(l>r) return NULL;
    
    int m = l + (r-l)/2;
    Node *&root = inorder[m];
    root->left = getBst(inorder, l, m-1);
    root->right = getBst(inorder, m+1, r);
    return root;
}

Node* buildBalancedTree(Node *root) {
    vector<Node*> inorder;
    getInorder(root, inorder);
    return getBst(inorder, 0, inorder.size()-1);
}