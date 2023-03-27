class Solution {
public:
   //Approach-1 Recursion
    int solve(int row , int col , vector<vector<int>>& triangle , int n){
        //base case 
        if(row==n-1) return triangle[row][col] ; //include in path 
         
        int down = triangle[row][col]+solve(row+1,col,triangle,n) ;
        int diagonal = triangle[row][col]+solve(row+1,col+1,triangle,n) ; 
        
        return min(down,diagonal);
    }
    //Approach-2 Memoization Time Complexity: O(N*N) , Space Complexity: O(N*N) + O(N) [For no of rows]
    //Fixed Starting Point and Variable ending point
    int solve2(int row , int col , vector<vector<int>>& triangle,vector<vector<int>>&dp , int n){
        //base case 
        if(row==n-1) return triangle[row][col] ; //include in path 
         if(dp[row][col]!=-1) return dp[row][col];
         //never out of boundary therefore no check for it
        int down = triangle[row][col]+solve2(row+1,col,triangle,dp,n) ;
        int diagonal = triangle[row][col]+solve2(row+1,col+1,triangle,dp,n) ; 
        
        return dp[row][col]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size()  ;
        vector<vector<int>>dp(n,vector<int>(n,-1));
      //   return solve(0,0,triangle,dp,n); //Approach-1 Recursion
     //   return solve2(0,0,triangle,dp,n);  //Approach-2 Memoization 
    //Approach-3 Tabulation Time Complexity: O(N*N) , Space Complexity: O(N*N) 
  /*  //Start Tabulation from opposite of recursion || Memoization Always 
    //base case at last row we can reach at any position try all
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j] ; 
    }
   
    //for ith row there are total j column try all path 
    //from n-2 as already done for n-1th 
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){ 
            int down = triangle[i][j] + dp[i+1][j] ;
            int diagonal = triangle[i][j] + dp[i+1][j+1] ;
            dp[i][j] = min(down,diagonal);
        }
    }
    return dp[0][0] ; //recursion call started from (0,0) thus in tabulation return it
    */
    //Approach-4 Tabulation(Space Optimization) Time Complexity: O(N*N) , Space Complexity: O(N) 
   vector<int>front(n,0) , curr(n,0) ; 
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j] ; 
    }
   
    //for ith row there are total j column try all path 
    //from n-2 as already done for n-1th 
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){ 
            int down = triangle[i][j] + front[j] ;
            int diagonal = triangle[i][j] + front[j+1] ;
            curr[j] = min(down,diagonal); //update current 
        }
        front=curr; //update front
    }
    return front[0] ;
    }
};
