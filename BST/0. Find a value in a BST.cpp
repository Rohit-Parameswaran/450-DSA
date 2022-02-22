bool search(Node* root, int x) {
    // Your code here
    if(!root) return false;
    if(root->data == x) return true;
    return search(root->left, x) || search(root->right, x);
}