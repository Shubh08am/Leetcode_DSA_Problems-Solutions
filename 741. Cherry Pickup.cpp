class Solution {
public:
    int dp[51][51][51][51] ; 
    int solve(int pr1,int pc1,int pr2,int pc2, vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        if(pr1>=n || pr2>=n || pc1>=m || pc2>=m || grid[pr1][pc1]==-1 || grid[pr2][pc2]==-1 ) return INT_MIN ; 
        
        if(dp[pr1][pc1][pr2][pc2] != -1) return dp[pr1][pc1][pr2][pc2];

        if((pr1==n-1 && pc1==m-1) || (pr2==n-1 && pc2==m-1)) return grid[n-1][m-1];
        int cherry = 0 ; 

        if(pr1==pr2 && pc1==pc2) cherry =  grid[pr2][pc2];
        else{
            cherry =  grid[pr1][pc1] + grid[pr2][pc2];
        }
            //DD , DR
            int first = max(solve(pr1+1,pc1,pr2+1,pc2,grid),solve(pr1+1,pc1,pr2,pc2+1,grid)) ; 
            // RR , RD
            int second = max(solve(pr1,pc1+1,pr2,pc2+1,grid),solve(pr1,pc1+1,pr2+1,pc2,grid)) ;
            cherry+=max(first,second);
        
        return dp[pr1][pc1][pr2][pc2]= cherry ; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,grid);
        return ans<0?0:ans;
    }
};
