class Solution {
public:
    // //Approach-1 Recursion
    int solve(int row,int col ,vector<vector<int>>& matrix){       
        int n=matrix.size() ; 
        //boundary check 
        if(row>=n || col>=n || col<0) return 1e9; //Not valid path return large value and won't take this path

        if(row==n-1) return matrix[row][col] ; //if destination reached i.e last row

        //3 ways 
        int down = matrix[row][col] + solve(row+1,col,matrix) ; 
        int leftDiagonal = matrix[row][col] + solve(row+1,col-1,matrix) ;
        int rightDiagonal = matrix[row][col] + solve(row+1,col+1,matrix) ;

        return min({down,leftDiagonal,rightDiagonal});
    }
    //Approach-2 Memoization Time Complexity: O(N*N) , Space Complexity: O(N*N) + O(N) [FOR PATH LENGTH i.e for row=0 to N]
        int solve2(int row,int col ,vector<vector<int>>& matrix,vector<vector<int>>&dp){       
        int n=matrix.size() ; 
        //boundary check 
        if(row>=n || col>=n || col<0) return 1e9; //Not valid path return large value and won't take this path

        if(row==n-1) return matrix[row][col] ; //if destination reached i.e last row
        
        if(dp[row][col]!=-1) return dp[row][col];
        //3 ways 
        int down = matrix[row][col] + solve2(row+1,col,matrix,dp) ; 
        int leftDiagonal = matrix[row][col] + solve2(row+1,col-1,matrix,dp) ;
        int rightDiagonal = matrix[row][col] + solve2(row+1,col+1,matrix,dp) ;

        return dp[row][col]=min({down,leftDiagonal,rightDiagonal});
    }
   /* int minFallingPathSum(vector<vector<int>>& matrix) { 
        int n=matrix.size() , ans = 1e9; 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //variable starting point and ending point try all path for starting point from row=0
        for(int i=0;i<n;i++){
        //    ans = min(ans,solve(0,i,matrix)); //row=0 and column = i // Approach-1 Recursion 
            ans = min(ans,solve2(0,i,matrix,dp)); //row=0 and column = i //Approach-2 Memoization
        }
    return ans;
    }
    */
    //Approach-3 Tabulation Time Complexity: O(N*N) , Space Complexity: O(N*N)
 /*   int minFallingPathSum(vector<vector<int>>& matrix) { 
        int n=matrix.size() , ans=1e9; 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //variable starting point and ending point try all path for starting point from row=0
        //we started recursion from (0,0) therefore tabulation starts from (n-1,ith) position and filling dp table
        for(int i=0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i] ;
        }
       
       //n-1th row already filled therefore starts from n-2th row
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){ //and fill col from 0 to n-1(including)
                //samee as recurrence relation and using dp as bottom up and
                // already dp is filled for that position of down,leftDiagonal,rightDiagonal
                int down=0,leftDiagonal=0,rightDiagonal=0; 
                   down = matrix[row][col] + dp[row+1][col] ; 

                  leftDiagonal = matrix[row][col] ;
                  if(col>0)    leftDiagonal+=dp[row+1][col-1] ;
                  else leftDiagonal+=1e9;//Not valid path add large value(so that it get excluded) and don't take this path

                  rightDiagonal = matrix[row][col] ;
                if(col+1<n)  rightDiagonal+=dp[row+1][col+1] ;
                else rightDiagonal+=1e9;//Not valid path add large value(so that it get excluded) and won't take this path

          dp[row][col]=min({down,leftDiagonal,rightDiagonal}); //assign minimum possible
            }
        }
    //from first row return minimum value as variable starting point
      for(int i=0;i<n;i++){ 
    //    cout<<dp[0][i] <<" ";
       ans=min(ans,dp[0][i]);
      }
    return ans;
    */
        //Approach-4 Tabulation Time Complexity: O(N*N) , Space Complexity: O(N)
    int minFallingPathSum(vector<vector<int>>& matrix) { 
        int n=matrix.size() , ans=1e9; 
        vector<int>prev(n,0) , curr(n,0);
        //variable starting point and ending point try all path for starting point from row=0
        //we started recursion from (0,0) therefore tabulation starts from (n-1,ith) position and filling dp table
        for(int i=0;i<n;i++){
            prev[i] = matrix[n-1][i] ;
        }
       
       //n-1th row already filled therefore starts from n-2th row
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){ //and fill col from 0 to n-1(including)
                //samee as recurrence relation and using dp as bottom up and
                // already dp is filled for that position of down,leftDiagonal,rightDiagonal
                int down=0,leftDiagonal=0,rightDiagonal=0; 
                   down = matrix[row][col] + prev[col] ; 

                  leftDiagonal = matrix[row][col] ;
                  if(col>0)    leftDiagonal+=prev[col-1] ;
                  else leftDiagonal+=1e9;//Not valid path add large value(so that it get excluded) and don't take this path

                  rightDiagonal = matrix[row][col] ;
                if(col+1<n)  rightDiagonal+=prev[col+1] ;
                else rightDiagonal+=1e9;//Not valid path add large value(so that it get excluded) and won't take this path

          curr[col]=min({down,leftDiagonal,rightDiagonal}); //assign minimum possible
            }
            prev=curr;
        }
    //from first row return minimum value as variable starting point
      for(int i=0;i<n;i++){ 
    //    cout<<prev[i] <<" ";
       ans=min(ans,prev[i]);
      }
    return ans;
    }
};
