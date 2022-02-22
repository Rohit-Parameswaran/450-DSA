class Solution
{
    public:
    int kthLargest(Node *root, int &k)
    {
        //Your code here
        if(!root) return 0;
        int ans;
        ans = kthLargest(root->right, k);
        if(ans != 0) return ans;
        
        --k;
        if(k == 0) return root->data;
        
        ans = kthLargest(root->left, k);
        if(ans != 0) return ans;
        
        return 0;
    }
};