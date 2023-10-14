class Solution {
public:
    int solve(int ind,int wallsToPaint,vector<int>& cost, vector<int>& time, vector<vector<int>>&dp) {
        int n = cost.size() ; 
        if(wallsToPaint<=0){
            return 0;
        }
        if(ind==n){
            return 1e9;
        }
        if(dp[ind][wallsToPaint]!=-1) return dp[ind][wallsToPaint];   
        int take = cost[ind]+solve(ind+1,wallsToPaint-1-time[ind],cost,time,dp) ;
        int notTake = solve(ind+1,wallsToPaint,cost,time,dp) ; 

    return dp[ind][wallsToPaint] = min(take,notTake) ; 
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size() ; 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ; 
        return solve(0,n,cost,time,dp) ; 
    }
};
