long long getMaxArea(long long arr[], int n)
{
    vector<int> prevSmaller(n, -1);
    vector<int> nextSmaller(n, n);

    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            nextSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            prevSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    long long maxi = INT_MIN;
    //Assume current element is the height of the rectangle
    //Largest rectangle that can be formed is of length = (NextSmaller - PreviousSmaller - 1) 
    for (int i = 0; i < n; ++i)
        maxi = max(maxi, (nextSmaller[i] - prevSmaller[i] - 1) * arr[i]);
    return maxi;
}