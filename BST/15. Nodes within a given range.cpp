//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here   
    if(!root) return 0;
  
    // if key is less than lower limit only recur for right subtree
    if(root->data < l)
        return getCount(root->right, l, h);
    // else if key is greater than upper limit only recur for left subtree
    else if(root->data > h)
        return getCount(root->left, l, h);
    // else recur for both children and add 1 (corresponding to this node)
    else 
        return getCount(root->left, l, h) + getCount(root->right, l, h) + 1;
}