class Solution {
public:
    int dp[3][1001] ; 
    int solve(int egg,int floor){
        if(egg==1) return floor; 
        if(floor==0 || floor == 1) return floor ; 
        if(dp[egg][floor]!=-1) return dp[egg][floor];
        int threshold = INT_MAX  , val = INT_MIN ; 
        for(int k=1;k<=floor;k++){
            int eggBreak = solve(egg-1,k-1) ; 
            int noEggBreak = solve(egg,floor-k) ; 
            val = 1 + max(eggBreak,noEggBreak);
            threshold = min(threshold,val);
        }
    return dp[egg][floor] = threshold ; 
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp)) ; 
        return solve(2,n) ; 
    }
};
