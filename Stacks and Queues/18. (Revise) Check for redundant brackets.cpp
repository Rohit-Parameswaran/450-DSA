#include<stack>
//This program also handles for unbalanced paranthesis expressions given as input 
bool findRedundantBrackets(string &str)
{
    stack<int> s;
    int n = str.size(), lc = -1;
    int lo = n;

    // lc - last matched closing paranthesis
    // lo - last matched opening paranthesis
    
    for(int i=0;i<n;++i) {
        if(str[i] == ')') {
            while(!s.empty() && str[s.top()] != '(') {
                s.pop();
            }
            //closing without corresponding opening brackets
            if(s.empty()) return true;
            //currently matched brackets immediately surround another matched pair
            else if(lo == s.top() + 1 && lc == i - 1) return true;
            //brackets should enclose atleast 3 characters ("operand operation operand")
            //paranthesis enclosing less than 3 characters are redundant / invalid
            else if(i - s.top() <= 2) return true;
            //else match paranthesis and reassign lc and lo
            else {
                lo = s.top(), lc = i;
                s.pop();
            }
        }
        //no need to push index of any character other than '(' and ')' 
        else if(str[i] == '(') {
            s.push(i);
        }
    }
    //if there exists an unmatched opening paranthesis the expression is invalid
    while(!s.empty()) {
        if(s.top() == '(') return true;
    	s.pop();
    }
    return false;
}
