class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int dp[m][n] ; 
        memset(dp,0,sizeof(dp));
        int x=indices.size(); 

        for(int i=0;i<x;i++){
            int row = indices[i][0] , col = indices[i][1] ; 
            for(int r=0;r<n;r++) dp[row][r]++;
            for(int c=0;c<m;c++) dp[c][col]++;
        }
        int odd=0;
         for(int r=0;r<m;r++){
              for(int c=0;c<n;c++){
                  odd+=dp[r][c]&1;
              }
         }
    return odd;
    }
};
