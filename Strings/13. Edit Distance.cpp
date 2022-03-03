int editDistance(string s, string t) {
    // Code here
    int r = s.size(), c = t.size();
    vector<vector<int>> dp(r+1, vector<int> (c+1));
    for(int i=0;i<=c;++i)
        dp[0][i] = i;
    for(int i=0;i<=r;++i)
        dp[i][0] = i;
        
    for(int i=1;i<=r;++i) {
        for(int j=1;j<=c;++j) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    
    return dp[r][c];
}