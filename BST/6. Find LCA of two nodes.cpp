Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
    if(!root) return NULL;

    if(n1 == root->data || n2 == root->data) return root;
    Node *l = LCA(root->left, n1, n2); //returns pointer to n1 or n2 if found. Else returns NULL
    Node *r = LCA(root->right, n1, n2);
    //For LCA n1 and n2 are present in both the left and right subtree. This is true only for the LCA 
    if(l && r)
        return root;
    //If LCA is one of n1 or n2
    //Then if(l && r) wouldn't be entered and node with value n1 or n2 (which is the LCA)
    //is returned to the previous calls

    //This works because it is guaranteed that both the nodes are present in the tree.
    //Otherwise we would have to manually check if the candidate LCA is actually the LCA by traversing the subtree  
    //with root as the LCA
    return l ? l : r;
}