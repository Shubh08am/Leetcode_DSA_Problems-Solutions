class Solution {
public:
    int dp[101][10001] ; 
    int solve(int egg,int floor){
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor; 
        if(dp[egg][floor]!=-1)  return dp[egg][floor];
        int val  = INT_MIN , threshold = INT_MAX;
        
        int low = 1 , high = floor ; 

        while(low<=high){

            int mid = low + (high-low)/2 ;
            int eggBreak = solve(egg-1,mid-1);
            int noEggBreak = solve(egg,floor-mid);

            //for worst case maximize 
            if(eggBreak < noEggBreak) low = mid + 1 ; 
            else high = mid-1;
            
            val = 1 + max(eggBreak,noEggBreak);
            //minimum step to reach threshold
            threshold = min(threshold,val) ; 
        }
        return dp[egg][floor] = threshold ; 
    }
    int superEggDrop(int k, int n) {
       memset(dp,-1,sizeof(dp));
       return solve(k,n);
    }
};
