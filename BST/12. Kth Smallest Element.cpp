class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int &k) {
        // add code here.
        if(!root) return -1;
        
        int res;
        res = KthSmallestElement(root->left, k);
        if(res != -1) return res;
        
        if(--k == 0) return root->data;
        
        res = KthSmallestElement(root->right, k);
        if(res != -1) return res;
    
        return -1;
    }
};