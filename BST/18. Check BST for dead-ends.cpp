bool isLeaf(Node* root) {
    if(root && !root->left && !root->right) return true;
    return false;
}

void getInorder(Node* root, vector<Node*> &arr) {
    if(!root) return;
    getInorder(root->left, arr);
    arr.push_back(root);
    getInorder(root->right, arr);
}

bool isDeadEnd(Node *root)
{
    vector<Node*> inorder;
    getInorder(root, inorder);
    
    int n = inorder.size();
    if(n == 1) return false;
    
    if(inorder[0]->data == 1 && inorder[1]->data == 2) return true;
    for(int i=1; i<n-1 ; ++i) {
        if(isLeaf(inorder[i]) && inorder[i]->data == inorder[i-1]->data + 1 && inorder[i]->data == inorder[i+1]->data - 1)
            return true;
    }
    return false;
}