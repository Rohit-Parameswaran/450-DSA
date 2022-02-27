string FirstNonRepeating(string s)
{
    // Code here
    vector<int> freq(256, 0);
    queue<char> q;
    string res;
    for (auto it : s)
    {
        ++freq[it];
        if (freq[it] == 1)
            q.push(it);
        while (!q.empty() && freq[q.front()] > 1)
            q.pop();
        if (q.empty())
            res.push_back('#');
        else
            res.push_back(q.front());
    }
    return res;
}