#include<algorithm>
#include<queue>
typedef TreeNode<int> Node;

vector<int> getNextLevel(queue<Node*> &q) {
	vector<int> res;
    while(!q.empty()) {
        auto root = q.front();
        q.pop();
        if(!root) {
            if(!q.empty()) q.push(NULL);
            break;
        }
        else {
            if(root->left){
            	res.push_back(root->left->val);
            	q.push(root->left);
            }
            if(root->right){
            	res.push_back(root->right->val);
            	q.push(root->right);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

bool anagram(TreeNode<int>*root1, int n, TreeNode<int>*root2, int m)
{
	// Write your code here
    if(!root1 || !root2 || n!=m) return false;
    
    queue<Node*> q1, q2;
    q1.push(root1);
    q1.push(NULL);
    q2.push(root2);
    q2.push(NULL);
    vector<int> t1(root1->val), t2(root2->val);
    
    while(!q1.empty()) {
        if(t1 != t2) return false;
        t1 = getNextLevel(q1);
        t2 = getNextLevel(q2);
    }
    return t1 == t2;
}