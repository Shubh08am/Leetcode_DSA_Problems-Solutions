const int mod = 1e9+7;
class Solution {
public:
    //Approach-1 Recursion  Time complexity : O(4^n) Space complexity : O(n)
    bool isNotValid(int nrow,int ncol,int m,int n){
        return nrow<0 || nrow>=m || ncol<0 || ncol>=n;
    }
    int solve(int row, int col,int m, int n, int maxMove) {
          
      if(isNotValid(row,col,m,n)) return 1;
      if(maxMove==0) return 0;

      int dx[]={-1,0,+1,0};
      int dy[]={0,-1,0,+1};
      int ans=0;
      for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];

            ans= (ans+solve(nrow,ncol,m,n,maxMove-1))%mod;
        }  
    return ans;
    }
    //Approach-2 Memoization Time complexity : O(n*m*maxMove) Space complexity : O(n*m*maxMove)+O(n) 
     int solve2(int row, int col,int m, int n, int maxMove,vector<vector<vector<int>>>&dp) {
          
      if(isNotValid(row,col,m,n)) return 1;
      if(maxMove==0) return 0;
      
      if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];

      int dx[]={-1,0,+1,0};
      int dy[]={0,-1,0,+1};
      int ans=0;
      for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];

            ans=(ans+solve2(nrow,ncol,m,n,maxMove-1,dp))%mod;
        }  
    return dp[row][col][maxMove]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //number of path to remove the ball out of boundary using dp 

        // return solve(startRow,startColumn,m,n,maxMove); //Approach 1:- Recursion 

        //3d-dp dp[row][col][maxMove]
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve2(startRow,startColumn,m,n,maxMove,dp); //Approach 2:- Memoization 

     }
};
