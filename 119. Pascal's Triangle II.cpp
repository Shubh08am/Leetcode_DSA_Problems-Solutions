class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(rowIndex+1) ;
        for(int i=0;i<=rowIndex;i++){
            //at every ith position (i+1) elements are there 
            dp[i].resize(i+1,1); // initially all 1 
            for(int j=1;j<i;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ;
            }
        }
        return dp.back();
    }
};
