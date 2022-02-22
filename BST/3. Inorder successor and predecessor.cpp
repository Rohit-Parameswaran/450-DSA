void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
    if(!root) return;
    findPreSuc(root->left, pre, suc, key);
    //storing last encountered element with value less than key
    if(root->key < key) pre = root;

    //storing least valued element with value > key 
    //just checking if suc == NULL is also correct
    if(root->key > key && (!suc || suc->key > root->key)) suc = root;
     
    findPreSuc(root->right, pre, suc, key);
}