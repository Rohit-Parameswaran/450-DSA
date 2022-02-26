int findMaxLen(string str) {
    // code here
    stack<int> s;
    s.push(-1);
    int maxi = 0;
    for(int i=0;i<str.size();++i) {
        if(str[i] == '(') s.push(i);
        else if(s.top() != -1 && str[s.top()] == '(') {
            s.pop();
            maxi = max(maxi, i - s.top());
        }
        else {
            s.push(i);
        }
    }
    return maxi;
}