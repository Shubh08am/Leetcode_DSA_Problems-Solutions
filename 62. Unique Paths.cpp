class Solution {
public:
   //Approach-1 Recursion(using bottom to up appraoch i.e from 0 to destination) :- TLE
   int solve(int row , int col, int m , int n){
       //base case :- If reached destination 
       if(row==m-1 && col==n-1) return 1; 
       //out of bound check 
       if(row>m || col>n) return 0;

       int bottom = solve(row+1,col,m,n) ; //go to down cell 
       int right = solve(row,col+1,m,n) ; //go to right cell 
        return bottom + right ;
   }
    //Approach-2 Recursion(using up to bottom appraoch i.e from destination to 0) :- TLE
   int solve2(int row , int col, int m , int n){
       //base case :- If reached destination 
       if(row==0 && col==0) return 1; 
       //out of bound check 
       if(row<0 || col<0) return 0;

       int up = solve2(row-1,col,m,n) ; //go to up cell 
       int left = solve2(row,col-1,m,n) ; //go to left cell 
        return up + left ;
   }
    //Approach-3 Memoization 
    int solve3(int row , int col, int m , int n,vector<vector<int>>&dp){
       //base case :- If reached destination 
       if(row==m-1 && col==n-1) return 1; 
       //out of bound check 
       if(row>=m || col>=n) return 0; // use if(row>=m || col>=n) return 0; here or create dp of size m+1 & n+1
       if(dp[row][col]!=-1) return dp[row][col];

       int bottom = solve3(row+1,col,m,n,dp) ; //go to down cell 
       int right = solve3(row,col+1,m,n,dp) ; //go to right cell 
        return dp[row][col]=bottom + right ;
   }
    //Approach-4 Memoization 
   int solve4(int row , int col, int m , int n,vector<vector<int>>&dp){
       //base case :- If reached destination 
       if(row==0 && col==0) return 1; 
       //out of bound check 
       if(row<0 || col<0) return 0;
       if(dp[row][col]!=-1) return dp[row][col];

       int up = solve4(row-1,col,m,n,dp) ; //go to up cell 
       int left = solve4(row,col-1,m,n,dp) ; //go to left cell 
        return dp[row][col]=  up + left ;
   }
    int uniquePaths(int m, int n) {
    //   return solve(0,0,m,n); //Approach-1
    //   return solve2(m-1,n-1,m,n); //Approach-2
      vector<vector<int>>dp(m,vector<int>(n,-1)) ; 
      return solve3(0,0,m,n,dp); //Approach-3
   //  return solve4(m-1,n-1,m,n,dp); //Approach-4
      }
};
