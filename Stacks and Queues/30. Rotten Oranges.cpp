bool isValid(int x, int y, int r, int c)
{
    return x >= 0 && y >= 0 && x < r && y < c;
}

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int r = grid.size(), c = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (grid[i][j] == 2)
                q.push({i, j});

    //delimiter to mark end of one iteration 
    q.push({-1, -1});
    int ans = 0, x, y;
    while (!q.empty())
    {
        auto curx = q.front().first, cury = q.front().second;
        q.pop();
        if (curx == -1 && cury == -1)
        {
            ++ans;
            if (!q.empty())
                q.push({-1, -1});
        }
        else
        {
            vector<int> xincs = {-1, 0, 1, 0};
            vector<int> yincs = {0, 1, 0, -1};
            for (int i = 0; i < 4; ++i)
            {
                x = curx + xincs[i], y = cury + yincs[i];
                if (isValid(x, y, r, c) && grid[x][y] == 1)
                {
                    //rotting adjacent oranges and pushing them into the queue for next iteration 
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
    }
    for (auto row : grid)
        for (auto it : row)
            if (it == 1)
                return -1;
    return ans - 1;
}