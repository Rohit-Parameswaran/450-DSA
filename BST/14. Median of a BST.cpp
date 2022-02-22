//if size of tree is odd return n/2th element
//if size of tree is even return average of n/2th element and its inorder predecessor
//track predecessor by maintaining a pre pointer

void getSize(Node* root, int &n) {
    if(!root) return;
    ++n;
    getSize(root->left, n);
    getSize(root->right, n);
}

float calcMedian(Node* root, int &n, int &c, Node* &pre) {
    if(!root) return -1;   
    
    float l = calcMedian(root->left, n, c, pre);
    if(l != -1) return l;
    
    if(c == n/2) {
        if(n & 1) return root->data;
        return (pre->data + root->data) / 2.0;
    }
    pre = root;
    
    ++c;
    float r = calcMedian(root->right, n, c, pre);
    if(r != -1) return r;
    
    return -1;
}

float findMedian(struct Node *root)
{
  //Code here
    int n = 0;
    getSize(root, n);
    int c = 0;
    Node *pre = NULL; 
    return calcMedian(root, n, c, pre);
}