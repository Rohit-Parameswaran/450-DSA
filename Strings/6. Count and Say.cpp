class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = countAndSay(n-1);
        string ans = "";
        int curAns = 1, size = s.size();
        for(int i=1;i<=size;++i) {
            if(i == size || s[i] != s[i-1]) {
                ans.push_back('0' + curAns);
                ans.push_back(s[i-1]);
                curAns = 1;
            }
            else ++curAns;
        }
        return ans;
    }
};