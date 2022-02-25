bool ispar(string x)
{
    // Your code here
    stack<char> s;
    for (auto it : x)
    {
        if (it == '{' || it == '(' || it == '[')
            s.push(it);
        else if (s.empty())
            return false;
        else if (it == '}' && s.top() == '{')
            s.pop();
        else if (it == ')' && s.top() == '(')
            s.pop();
        else if (it == ']' && s.top() == '[')
            s.pop();
        else
            return false;
    }
    return s.empty();
}