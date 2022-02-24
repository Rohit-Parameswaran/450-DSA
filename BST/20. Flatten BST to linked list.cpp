//////////////////////////////////////// Method 1 ///////////////////////// 
// Tracking head and tail of flattened subtree //////////////////

struct Info {
    Node* head;
    Node* tail;
};

public:
Info flattenUtil(Node *root) {
    if(!root) {return {NULL, NULL};}
    
    Info l = flattenUtil(root->left);
    Info r = flattenUtil(root->right);
    root->left = NULL;
    if(l.tail) l.tail->right = root;
    if(r.head) root->right = r.head;
    return {l.head ? l.head : root, r.tail ? r.tail : root};
}

void flatten(Node *&root)
{
    //code here
    Info res = flattenUtil(root);
    root = res.head;
}

//////////////////////////////////////// Method 2 ///////////////////////// 
// Tracking predecessors and assigning their next pointer to current root /