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
    //Approach-4 Memoization  Space Complexity: O((N-1)+(M-1)) + O(M*N) , Time Complexity: O(M*N)
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
    //  vector<vector<int>>dp(m,vector<int>(n,-1)) ; 
   //   return solve3(0,0,m,n,dp); //Approach-3
   //  return solve4(m-1,n-1,m,n,dp); //Approach-4
   //Approach-5 Tabulation  Time Complexity: O(M*N) , Space Complexity: O(M*N)
  // dp[0][0]=1; //use here or inside loop also works
    /* for(int row=0;row<m;row++){
         for(int col=0;col<n;col++){
                if(row==0 && col==0){
                    dp[row][col]=1;
                }
                else{
                //from recurrence 
                int up=0,left=0;
                if(row>0) up = dp[row-1][col] ; //go to up cell 
                if(col>0)  left = dp[row][col-1] ; //go to left cell 
                dp[row][col]=  up + left ;
                }
         }
     }
     return dp[m-1][n-1];
     */
    //Approach-6 Tabulation(With Space Optimization) Tabulation  Time Complexity: O(M*N) , Space Complexity: O(N)
    //use single vector prev(for previous row and curr for current row) 
    vector<int>prev(n,0) ;  // for no of column 
    for(int row=0;row<m;row++){
              vector<int>curr(n,0) ; 
              for(int col=0;col<n;col++){
                if(row==0 && col==0){
                    curr[col]=1;
                }
                else{
                    //from recurrence 
                int up=0,left=0;
                if(row>0) up = prev[col]; //go to up cell 
                if(col>0)  left = curr[col-1] ; //go to left cell 
                curr[col]=  up + left ;
                }
              }
              prev=curr;
        }
    return prev[n-1] ; 
    }
};
