class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);        
        for(int i = 0; i <n; i++) {
            // ith row has i+1 elements
            dp[i].resize(i+1,1);//initially, 1      
            // 1st and last elements will be 1, rest will be sum of two elements from above row 
            for(int j = 1; j < i; j++){         
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]; //prev 2 level element sum 
            }           
        }
        return dp;
    }
};
