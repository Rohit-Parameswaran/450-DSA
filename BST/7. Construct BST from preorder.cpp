class Solution
{
    int i = 0;

public:
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_val = INT_MAX)
    {
        //return NULL if current value is greater than parent_val passed
        if (i >= preorder.size() || preorder[i] > parent_val)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i]);
        ++i;
        //values in left subtree must be less than current node value(preorder[i-1])
        root->left = bstFromPreorder(preorder, preorder[i - 1]);
        //values in right subtree must be less than parent node value(parent_val)
        root->right = bstFromPreorder(preorder, parent_val);
        return root;
    }
};

//Alternate Logic
// typedef TreeNode Node;
// class Solution {
// public:
//     Node* genBST(vector<int> &arr, int l, int r, vector<int> &ng, vector<int> &nl) {
//         if(l>r) return nullptr;
//         else if(l == r) return new Node(arr[l]);
        
//         int ltree = nl[l], rtree = ng[l];
        
//         return new Node(arr[l], genBST(arr, ltree, rtree-1, ng, nl), genBST(arr, rtree, r, ng, nl));
//     }
    
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         stack<int> s;
//         vector<int> ng(preorder.size(), preorder.size()), nl(preorder.size(), preorder.size());
        
//         for(int i=0;i<preorder.size();++i) {
//             while(!s.empty() && preorder[s.top()] < preorder[i]){
//                 ng[s.top()] = i;
//                 s.pop();
//             }
//             s.push(i);
//         }
        
//         while(!s.empty()) s.pop();
        
//         for(int i=0;i<preorder.size();++i) {
//             while(!s.empty() && preorder[s.top()] > preorder[i]){
//                 nl[s.top()] = i;
//                 s.pop();
//             }
//             s.push(i);
//         }
        
//         return genBST(preorder, 0, preorder.size()-1, ng, nl);
//     }
// };