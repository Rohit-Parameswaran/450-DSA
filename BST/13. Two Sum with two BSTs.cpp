// for O(n) approach store inorder traversal of one BST in unordered set 
// and traverse second BST to search for each corresponding element in set

class Solution
{
public:
    bool find(Node* root, int key) {
        while(root) {
            if(root->data == key) return true;
            if(root->data < key) root = root->right;
            else root = root->left;
        }
        return false;
    }
    
    int countPairs(Node* root1, Node* root2, int &x)
    {
        if(!root1 || !root2) return 0;
        int l = countPairs(root1->left, root2, x);
        int r = countPairs(root1->right, root2, x);
        if(x - root1->data > 0 && find(root2, x - root1->data))
            return l + r + 1;
        return l + r;
    }
};