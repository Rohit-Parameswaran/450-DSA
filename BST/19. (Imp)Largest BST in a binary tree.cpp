bool getLargestBst(Node* root, vector<int> &ans, vector<int> &ret) {
        if(!root) {return true;}
        
        //Stores inorder of left subtree if it is a bst, else empty vector
        vector<int> l;     
        //Stores inorder of right subtree if it is a bst, else empty vector
        vector<int> r;
        
        //returns true if left subtree is a BST
        bool lflag = getLargestBst(root->left, ans, l);
        //returns true if left subtree is a BST
        bool rflag = getLargestBst(root->right, ans, r);
        
        //if both left and right subtrees are BSTs
        if(lflag && rflag) {
            //check if current subtree is a BST by comparing root node with inorder predecessor and successor
            if((!root->left || (l.back() < root->data)) && (!root->right || (r[0] > root->data))){
                vector<int> temp = l;
                temp.push_back(root->data);
                temp.insert(temp.end(), r.begin(), r.end());
                //storing inorder of current subtree
                ret = temp;

                //reassigning ans vector to current subtree if it is of greater size
                ans = ans.size() < temp.size() ? temp : ans;
                return true;
            }
        }
        return false;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	vector<int> ans;
    	vector<int> t;
    	getLargestBst(root, ans, t);
    	return ans.size();
    }

//Space efficient solution
//     class Solution{
//     struct Subtree {
//         bool isBst;
//         int min;
//         int max;
//         int size;
//     };
//     public:
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     Subtree getLargestBst(Node* root, int &n) {
//         if(!root) {
//             return {true, INT_MAX, INT_MIN, 0};
//         }
        
//         Subtree lst = getLargestBst(root->left, n);
//         Subtree rst = getLargestBst(root->right, n);
        
//         int cmin = min(root->data, min(lst.min, rst.min));
//         int cmax = max(root->data, max(lst.max, rst.max));
        
//         if(lst.isBst && rst.isBst) {
//             if(lst.max < root->data && rst.min > root->data){
//                 if(n < lst.size + rst.size + 1)
//                     n = lst.size + rst.size + 1;
//                 return {true, cmin, cmax, lst.size + rst.size + 1};
//             }
//         }
//         return {false, cmin, cmax, lst.size + rst.size + 1};
//     }
    
//     int largestBst(Node *root)
//     {
//     	//Your code here
//     	int n;
//     	getLargestBst(root, n);
//     	return n;
//     }
// };