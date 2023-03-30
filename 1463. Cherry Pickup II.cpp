class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(3^N * 3^N) , Space Complexity:O(N) [FOR PATH LENGTH i.e for row=0 to N]
    int solve(int i,int j1,int j2,vector<vector<int>>& grid){
         int n=grid.size() , m=grid[0].size() , maxi=-1e9;
         //base case:- (1)Boundary Check 
         if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;

         //(2) destination reach i.e last row 
         if(i==n-1){
             if(j1==j2) return grid[n-1][j1];  //both robots at same cell :- Count once only 
             else return grid[n-1][j1]+grid[n-1][j2]; //both robots at different cell :- Count for both differently 
         }

         //Explore All paths i.e 9 paths 
         for(int dj1=-1;dj1<=+1;dj1++){
             for(int dj2=-1;dj2<=+1;dj2++){
               int value = 0 ; 
               if(j1==j2) value = grid[i][j1];   
             else value = grid[i][j1]+grid[i][j2]; 
             
            value+=solve(i+1,j1+dj1,j2+dj2,grid);
            maxi=max(maxi,value);
          }
        }
    return maxi;
    }
        //Approach-2 Memoization Time Complexity: O(N*M*M)*9 , Space Complexity:O(N*M*M) + O(N) [FOR PATH LENGTH i.e for row=0 to N]
    int solve2(int i,int j1,int j2,vector<vector<int>>& grid ,vector<vector<vector<int>>>&dp){
         int n=grid.size() , m=grid[0].size() , maxi=-1e9;
         //base case:- (1)Boundary Check 
         if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;

         //(2) destination reach i.e last row 
         if(i==n-1){
             if(j1==j2) return grid[n-1][j1];  //both robots at same cell :- Count once only 
             else return grid[n-1][j1]+grid[n-1][j2]; //both robots at different cell :- Count for both differently 
         }
        
        if(dp[i][j1][j2] !=-1) return dp[i][j1][j2] ;
         //Explore All paths i.e 9 paths 
         for(int dj1=-1;dj1<=+1;dj1++){
             for(int dj2=-1;dj2<=+1;dj2++){
                if(j1==j2) maxi = max(maxi,grid[i][j1] + solve2(i+1,j1+dj1,j2+dj2,grid,dp));   
             else maxi = max(maxi,grid[i][j1]+grid[i][j2]+solve2(i+1,j1+dj1,j2+dj2,grid,dp)); 
           }
        }
    return dp[i][j1][j2] = maxi;
    } 
    //Approach-3 Tabulation Time Complexity: O(N*M*M)*9 , Space Complexity:O(N*M*M)
    int tabulation(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    // base case when i=n-1 j1 and j2 can be from 0 to m-1 anything
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // for last row(i=n-1) already filled start filling from i=n-2 onwards
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e9;
                // All path explored
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        // check valid
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e9; // not a valid path don't take it
                        }
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
 //Approach-4 Tabulation with Space Optimization Time Complexity: O(N*M*M)*9 , Space Complexity:O(M*M)
int tabulationSpaceOptimization(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    // base case when i=n-1 j1 and j2 can be from 0 to m-1 anything
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // for last row(i=n-1) already filled start filling from i=n-2 onwards
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e9;
                // All path explored
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        // check valid
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value += front[j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e9; // not a valid path don't take it
                        }
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
         front = curr;
    }
    return front[0][m - 1];
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1))) ; //int dp[n][m][m] 
      //  return solve(0,0,m-1,grid); //Approach-1 Recursion 
      //    return solve2(0,0,m-1,grid,dp); //Approach-2 Memoization 
    //  return tabulation(grid) ; //Approach-3 Tabulation
        return tabulationSpaceOptimization(grid) ; //Approach-4 Tabulation with Space Optimization
    }
};
