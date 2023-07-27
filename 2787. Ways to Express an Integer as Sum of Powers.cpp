class Solution {
public:
    int mod= 1e9+7;
    int solve(int n,int x,int i,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(i> n) return 0;
        
        if(dp[n][i]!=-1) return dp[n][i];
        int include=0;
        include= solve( (n- (long long)pow(i,x)%mod )%mod , x, i+1 ,dp)%mod;
        
        int exclude=0;
        exclude= solve(n,x,i+1,dp)%mod;
        return dp[n][i]= (include + exclude)%mod;
    }
    
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,1,dp);
    }
};
