const int mod = 1e9+7 ; 

class Solution {
public:
    int solve(int i,int j,int pathSum,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int n=grid.size() , m=grid[0].size() ; 

        if(i>n-1 || j>m-1) return 0;

        // DESTINATION REACHED 
        if(i==n-1 && j==m-1){ 
         //   cout<< pathSum+grid[i][j] << " ";
            return (pathSum+grid[i][j])%k==0 ; 
        }

        if(dp[i][j][pathSum]!=-1) return dp[i][j][pathSum] ; 

        //TO AVOID TLE TAKING PATHSUM MODULO WITH K 
        int down = solve(i+1,j,(pathSum+grid[i][j])%k,k,grid,dp) ; 
        int right = solve(i,j+1,(pathSum+grid[i][j])%k,k,grid,dp) ;

        return dp[i][j][pathSum]=(down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size() , m=grid[0].size() ; 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return solve(0,0,0,k,grid,dp);
    }
};
