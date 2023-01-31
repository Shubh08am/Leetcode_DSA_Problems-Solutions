class Solution {
public: 
//classic dp quest 
// do later :) --> only to complete december challenge
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                int op1 = (text1[i-1]==text2[j-1])+dp[i-1][j-1];
                int op2 = dp[i-1][j];
                int op3 = dp[i][j-1];
                dp[i][j] = max({op1, op2, op3});
            }
        }
        return dp[n][m];
    }
};
