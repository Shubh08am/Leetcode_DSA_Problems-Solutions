class Solution {
public:
//Approach-1 Recursion
  /*   int solve(int ind , vector<int>& cost){
       if(ind<=1) return 0;
       int jump1 = solve(ind-1,cost) + cost[ind-1] ; 
       int jump2  = solve(ind-2,cost) + cost[ind-2] ; 

       return min(jump1,jump2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return solve(n,cost);
    }
};
*/
    //APPROACH-2
    //memoization approach -> S.C ->O(N)+O(N) & T.C-> O(N) 
    /* int solve(int ind , vector<int>& cost,vector<int>&dp){
       if(ind<=1) return 0;
       if(dp[ind]!=-1) return dp[ind]; 
       int jump1 = solve(ind-1,cost,dp) + cost[ind-1] ; 
       int jump2  = solve(ind-2,cost,dp) + cost[ind-2] ; 

       return dp[ind] = min(jump1,jump2);
    }
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(n,cost,dp);
    }
    */
    //APPROACH-3
   /*//Tabulation approach(bottom up) -> S.C ->O(N) & T.C-> O(N) 
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        //from base case assign in dp values 
        dp[0]=dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]) ;
        }
        return dp[n] ;
        */
     //APPROACH-4
    //Tabulation approach(bottom up) -> S.C ->O(1) & T.C-> O(N) 
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev=0;int prev2=0;
        for(int i=2;i<=n;i++){
            int curri = min(prev+cost[i-1],prev2+cost[i-2]) ; 
            prev2=prev;
            prev=curri;
        }
        return prev ;
    }
};
