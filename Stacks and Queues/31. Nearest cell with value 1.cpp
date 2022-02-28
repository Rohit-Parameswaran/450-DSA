bool isValid(int x, int y, int r, int c)
{
    return x >= 0 && y >= 0 && x < r && y < c;
}

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int r = grid.size(), c = grid[0].size();
    vector<vector<int>> res(r, vector<int>(c, INT_MAX));
    queue<vector<int>> q;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (grid[i][j])
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }
    q.push({-1, -1});

    int ans = 0, x, y;
    vector<int> rdir = {-1, 0, 1, 0};
    vector<int> cdir = {0, 1, 0, -1};

    while (!q.empty())
    {
        int curx = q.front()[0], cury = q.front()[1];
        q.pop();
        if (curx == -1 && cury == -1)
        {
            ++ans;
            if (!q.empty())
                q.push({-1, -1});
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                x = curx + rdir[i], y = cury + cdir[i];
                if (isValid(x, y, r, c) && res[x][y] > ans + 1)
                {
                    res[x][y] = ans + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return res;
}