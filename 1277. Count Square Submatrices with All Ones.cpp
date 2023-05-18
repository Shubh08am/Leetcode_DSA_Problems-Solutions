class Solution {
public:
    //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
    int tabulation(vector<vector<int>>& matrix){
     //tabulation more intutive 
        //till each cell how many square possible is stored in dp
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0)) ; 

        //fill first row and first column as it is 
    
        //fillinf first column
        for(int row=0;row<n;row++) dp[row][0] = matrix[row][0];

        //filling first row
        for(int col=0;col<m;col++) dp[0][col] = matrix[0][col];


        for(int row=1;row<n;row++){
                for(int col=1;col<m;col++){
                   if(matrix[row][col]==0)  dp[row][col]=0;

                   else if(matrix[row][col]==1){
                        int square = min({dp[row][col-1],dp[row-1][col],dp[row-1][col-1]}) ; 
                        dp[row][col]=1+square;
                   }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
              for(int col=0;col<m;col++){
                     ans+=dp[row][col];
               }
        }
         return ans;
}  
   //Approach-1 Recursion Time Complexity: EXPONENTIAL (3^N)
    int solve(int i,int j,vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        //VALID CHECK 
        if(i<0 or i>=n or j<0 or j>=m or matrix[i][j] == 0){
            return 0;
        }
 
        int prevCol = solve(i,j-1,matrix);
        int prevRow = solve(i-1, j,matrix);
        int diagonal = solve(i-1,j-1,matrix);

        return 1 + min({prevCol, prevRow, diagonal});
    }
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M)+O(N), where N = total no. of rows and M = total no. of columns
     int solve2(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int n=matrix.size(),m=matrix[0].size();
        //VALID CHECK 
        if(i<0 or i>=n or j<0 or j>=m or matrix[i][j] == 0){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int prevCol = solve2(i,j-1,matrix,dp);
        int prevRow = solve2(i-1, j,matrix,dp);
        int diagonal = solve2(i-1,j-1,matrix,dp);

        return dp[i][j]=1 + min({prevCol, prevRow, diagonal});
    }

     int countSquares(vector<vector<int>>& matrix) {
         int n=matrix.size(),m=matrix[0].size();
         int ans = 0 , ans2=0; 
         vector<vector<int>> dp(n, vector<int>(m,-1));
          for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j] == 1){
                 //   ans += solve(i,j,matrix);
                    ans2 += solve2(i,j,matrix,dp);
                }
            }
        } 
      //  return ans; //Approach-1 Recursion
      
        return ans2; //Approach-2 Memoization
       return tabulation(matrix) ; //Approach-3 Tabulation
     }
};
