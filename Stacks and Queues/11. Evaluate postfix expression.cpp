int evaluatePostfix(string str)
{
    // Your code here
    stack<int> s;
    for (auto it : str)
    {
        if (isdigit(it))
            s.push(it - '0');
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int c;
            if (it == '+')
                c = a + b;
            else if (it == '-')
                c = a - b;
            else if (it == '*')
                c = a * b;
            else if (it == '/')
                c = a / b;
            s.push(c);
        }
    }
    return s.top();
}