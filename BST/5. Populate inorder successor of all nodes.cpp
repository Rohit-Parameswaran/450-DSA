class Solution
{
    Node *pre = NULL;
public:
    
    void populateNext(Node *root)
    {
        //code here
        if(!root) return;
        populateNext(root->left);

        // Assigning next of pre to current node
        // Assigning pre to current node before traversing to the next node
        if(pre) pre->next = root;
        pre = root;

        populateNext(root->right);
    }
};