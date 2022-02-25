int celebrity(vector<vector<int>> &mat, int n)
{
    // code here
    int a = n - 2, b = n - 1, cel = -1;
    while (a >= 0 && b >= 0)
    {
        if (mat[b][a])
        {
            b = a - 1;
            cel = a;
            swap(a, b);
        }
        else
        {
            a = a - 1;
            cel = b;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == cel)
            continue;
        if (mat[cel][i] || !mat[i][cel])
            return -1;
    }
    return cel;
}