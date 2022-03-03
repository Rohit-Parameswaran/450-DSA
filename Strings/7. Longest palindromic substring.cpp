class Solution {
    int ans = 1, anspos = 0;
    public:
        void checkPal(string &s, int &n, int start, int end, int curl) {
            while(s[start] == s[end] && start >= 0 && end < n) {
                curl += 2;
                start--, end++;
            }
            if(ans < curl) {
                ans = curl;
                anspos = start+1;
            }
        }

        string longestPalin (string s) {
            // code here
            int n = s.size();
            for(int i=0;i<n;++i) {
                //checking for palindrome of odd length
                checkPal(s, n, i-1, i+1, 1);
                //checking for palindrome of even length
                checkPal(s, n, i-1, i, 0);
            }
            return s.substr(anspos, ans);
        }
};