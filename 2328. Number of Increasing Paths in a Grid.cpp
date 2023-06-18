const int mod = 1e9+7;

class Solution {
public:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m ;
    }
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size() , m = grid[0].size()  ; 

        if(!isValid(row,col,n,m)) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col] ; 
        
        int dx[] = {-1,0,+1,0} ; 
        int dy[] = {0,-1,0,+1} ; 

        int lenOfLIS = 1 ; //atleast 1 

        for(int i=0;i<4;i++){
            int nr = row + dx[i] ;
            int nc = col + dy[i] ; 

            if(isValid(nr,nc,n,m) && grid[nr][nc]>grid[row][col]){
                lenOfLIS = (lenOfLIS+solve(nr,nc,grid,dp))%mod ; 
            }
        }
    return dp[row][col] = lenOfLIS ;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size()  ; 
        vector<vector<int>>dp(n,vector<int>(m,-1)) ; 
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                ans = (ans+solve(row,col,grid,dp))%mod ;
            }
        }
    return ans;
    }
};
