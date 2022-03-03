int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    int n = nums.size(), minc = INT_MAX, curc;
    vector<int> dp(n, INT_MAX);
    for(int i=0;i<n;++i) {
        //this is the line say L(i) where nums[i] is the last word
        curc = i < n-1 ? sq(k - nums[i]) : 0;
        if(i - 1 >= 0) curc += dp[i-1];
        int curline = nums[i];
        //iterate backwards and fix the first word of the line L(i) and calculate total cost
        // track the minimum cost
        for(int j=i-1;j>=0;--j) {
            curline += nums[j] + 1;
            if(curline > k) break;

            //trailing spaces in the last line do not count towards the cost
            if(i == n-1)
                curc = min(curc, (j-1 >= 0 ? dp[j-1] : 0));
            else
                curc = min(curc, (j-1 >= 0 ? dp[j-1] : 0) + sq(k - curline));
        }
        dp[i] = curc;
        minc = min(minc, curc);
    }

    //return last element in the dp array
    return dp[n-1];
} 