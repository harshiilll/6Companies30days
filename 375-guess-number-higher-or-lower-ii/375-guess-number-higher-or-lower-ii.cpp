class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        for(int len = 2;len <= n; ++len){
            int l = 1, r = len;
            while(r <= n) {
                int ans = INT_MAX;
                for(int i=l; i<=r; i++){
                    ans = min(ans, i + max(dp[l][i-1], dp[i+1][r]));
                }
                dp[l][r] = ans;
                l++, r++;
            }
        }
        return dp[1][n];
    }
};