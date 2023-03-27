class Solution {
public:
     //Approach-1 Recursion
    int solve(int row,int col,vector<vector<int>>& grid){
     if(row==0 && col==0){
         return grid[0][0] ; //take this much cost of first cell
      }
     if(row<0 || col<0) return 1e9 ; //don't take this path and and a large value
        int up =   grid[row][col] + solve(row-1,col,grid) ; 
       int left =  grid[row][col] + solve(row,col-1,grid) ;  
       return min(up,left);
    }
    //Approach-2 Memoization Time Complexity: O(N*M) , Space Complexity: O((M-1)+(N-1)) + O(N*M)
    int solve2(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
     if(row==0 && col==0){
         return grid[0][0] ; //take this much cost of first cell
      }
     if(row<0 || col<0) return 1e9 ; //don't take this path and and a large value
     if(dp[row][col]!=-1) return dp[row][col];

        int up =   grid[row][col] + solve2(row-1,col,grid,dp) ; 
       int left =  grid[row][col] + solve2(row,col-1,grid,dp) ;  
       return dp[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int cost = INT_MAX , n = grid.size() , m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        //return solve(n-1,m-1,grid); //Approach-1 Recursion
       // return solve2(n-1,m-1,grid,dp); //Approach-2 Memoization
       //Approach-3 Tabulation Time Complexity: O(N*M) , Space Complexity: O(N*M)
    /*   for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(i==0 && j==0) dp[i][j] = grid[0][0] ; 
             else{
                int up = grid[i][j] ; 
                if(i>0) up+=dp[i-1][j] ; 
                else up+=1e9 ; //don't take this path and and a large value
                  
               int left = grid[i][j] ; 
                if(j>0) left+=dp[i][j-1] ; 
                else left+=1e9 ; //don't take this path and and a large value

                //take min path 
                dp[i][j] = min(up,left) ;
             }
          }
       }
       return dp[n-1][m-1];
      */
      //Approach-4 Tabulation Time Complexity: O(N*M) , Space Complexity: O(M)
         vector<int>prev(m,0) ; 
       for(int i=0;i<n;i++){
               vector<int>curr(m,0) ; 
          for(int j=0;j<m;j++){
             if(i==0 && j==0) curr[j] = grid[0][0] ; //assign to curr row
             else{
                int up = grid[i][j] ; 
                if(i>0) up+=prev[j];  //assign prev row jth column
                else up+=1e9 ; //don't take this path and and a large value
                  
               int left = grid[i][j] ; 
                if(j>0) left+=curr[j-1] ; //assign curr row j-1th column
                else left+=1e9 ; //don't take this path and and a large value

                //take min path and assign to curr row
                curr[j] = min(up,left) ;
             }
          }
          prev=curr; //update prev row to curr row and again compute currrent row
       }
       return prev[m-1];
    }
};
