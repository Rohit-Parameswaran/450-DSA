class Solution
{
    //For iterative inorder traversal of the two BSTs
    stack<Node*> s1, s2;
    public:
    //pushes all nodes that appear before root in inorder traversal
    void push(stack<Node*> &s, Node* root) {
        Node* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
    }
    
    // Pops and returns topmost node. 
    // And pushes all nodes appearing after the topmost node in inorder traversal till its right child
    Node* pop(stack<Node*> &s) {
        Node *t = s.top();
        s.pop();
        push(s, t->right);
        return t;
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       push(s1, root1);
       push(s2, root2);
       
       vector<int> res;
       //Executes until both the stacks are empty i.e, both trees are fully traversed
       while(!s1.empty() || !s2.empty()) {
           //if one tree is empty the topmost element for that tree is assumed to be NULL
           //this causes all the remaining nodes of the non-empty tree to be processed
           int a = s1.empty() ? INT_MAX : s1.top()->data;
           int b = s2.empty() ? INT_MAX : s2.top()->data;
           
           //Merging logic
           if(a <= b) {
               Node* temp = pop(s1);
               res.push_back(temp->data);
           }
           else {
               Node* temp = pop(s2);
               res.push_back(temp->data);
           }
       }
       return res;
    }
};