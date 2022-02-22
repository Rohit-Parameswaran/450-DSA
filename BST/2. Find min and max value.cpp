int minValue(Node* root) {
    // Code here
    if(!root) return -1;
    Node *t = root;
    while(t->left) 
        t = t->left;
}

int maxValue(Node* root) {
    if(!root) return -1;
    Node *t = root;
    while(t->right) 
        t = t->right;
    return t->data;
}