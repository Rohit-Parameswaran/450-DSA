class Solution {
    int i = 0;
  public:
    int canRepresentBST(int arr[], int n) {
        // code here
        stack<int> s;
        int pre = INT_MIN;
        // Basic Preorder idea: Once we reach the right subtree of a node in preorder traversal *ALL* remaining 
        // elements should be greater than that element.

        // Similar to next greater element problem
        // An element is popped when its right subtree is NULL or is about to be traversed
        // Keep track of last popped element (pre). 
        // If the element to be inserted into the stack is lesser than pre, the BST cannot be formed
        for(int i=0; i<n ; ++i) {
            if(s.empty()) s.push(arr[i]);
            else {

                // when current element is lesser than top of stack
                if(arr[i] < s.top()) {
                    // when current element is lesser than the previously popped element (i.e, whose right subtree has been traversed or is being traversed)
                    // return false since it violates the basic preorder idea mentioned above
                    if(arr[i] < pre) return false;
                    else s.push(arr[i]);                    
                }
                //duplicate elements imply invalid preorder traversal
                else if(arr[i] == s.top()) return false;

                //keep popping as long as current element is greater than top of stack. 
                // The current element will appear in the right subtree of the last popped element 
                else {
                    while(!s.empty() && arr[i] > s.top()) {
                        pre = s.top();
                        s.pop();
                    }
                    s.push(arr[i]);
                }
            }
        }
        return true;
    }
};