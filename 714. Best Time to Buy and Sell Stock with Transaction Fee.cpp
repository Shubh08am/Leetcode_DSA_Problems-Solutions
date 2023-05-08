class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(2^N)[Take,notTake] Space Complexity: O(N)[Auxillary Stack Space]
        int solve(int ind,int buy,int fee,vector<int>&prices){
        int n=prices.size(),profit=0;
        //We can charge the transaction fee at time of buying or selling stock our choice but charge once only
        if(ind==n) return 0;
 
        if(buy){
            int take=-prices[ind]+solve(ind+1,0,fee,prices);
            int notTake=0+solve(ind+1,1,fee,prices);
            profit=max(take,notTake);
        }
        else{
            int take = prices[ind]+solve(ind+1,1,fee,prices)-fee;
            int notTake = 0+solve(ind+1,0,fee,prices);
            profit=max(take,notTake);
        }
    return profit;
    }

  //Approach-2 Memoization Time Complexity: O(N*2)[buy->0 or 1 --> 2 states] 
  // Space Complexity:O(N*2) + O(N) [O(N)[Auxillary Stack Space]]
    int solve2(int ind,int buy,int fee,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size(),profit=0;
        //We can charge the transaction fee at time of buying or selling stock our choice but charge once only

        if(ind==n) return 0;
 
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int take=-prices[ind]+solve2(ind+1,0,fee,prices,dp);
            int notTake=0+solve2(ind+1,1,fee,prices,dp);
            profit=max(take,notTake);
        }
        else{
            int take = prices[ind]+solve2(ind+1,1,fee,prices,dp)-fee;
            int notTake = 0+solve2(ind+1,0,fee,prices,dp);
            profit=max(take,notTake);
        }
    return dp[ind][buy]=profit;
    }
    //Approach-3 Tabulation Time Complexity: O(N)  Space Complexity:O(N*2) 
    int tabulation(vector<int>&prices,int fee){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //As, dp already initialized with 0 no need to write base cases explicitly 

        for(int ind=n-1;ind>=0;ind--){
            //eliminating buy loop 
            dp[ind][1]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            dp[ind][0]=max(prices[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
        }
        return dp[0][1];
    }
     //Approach-4 Tabulation With Space Optimization Time Complexity: O(N)   Space Complexity:O(1)  
     int tabulationWithSpaceOptimization(vector<int>& prices,int fee){
              int n=prices.size();
              vector<int>ahead(2,0),curr(2,0);
              //As, dp already initialized with 0 no need to write base cases explicitly 

              for(int ind=n-1;ind>=0;ind--){
                   //eliminating buy loop 
                curr[1]=max(-prices[ind]+ahead[0],0+ahead[1]);
                curr[0]=max(prices[ind]-fee+ahead[1],0+ahead[0]);

                ahead=curr;
              }
        return ahead[1];
     }
    //Approach-5 Tabulation With Space Optimization Using Variables Time Complexity: O(N)   Space Complexity:O(1)  
     int tabulationWithSpaceOptimization2(vector<int>& prices,int fee){
              int n=prices.size();
              int currBuy,currNotBuy,aheadBuy=0,aheadNotBuy=0;

              for(int ind=n-1;ind>=0;ind--){
                currBuy=max(-prices[ind]+aheadNotBuy,0+aheadBuy);
                currNotBuy=max(prices[ind]-fee+aheadBuy,0+aheadNotBuy);

                aheadBuy=currBuy;
                aheadNotBuy=currNotBuy;
              }
        return aheadBuy;
     }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();

       // return solve(0,1,fee,prices); //Approach-1 Recursion

     //   vector<vector<int>>dp(n,vector<int>(2,-1));
     //   return solve2(0,1,fee,prices,dp); //Approach-2 Memoization
     //   return tabulation(prices,fee);    //Approach-3 tabulation
     //     return tabulationWithSpaceOptimization(prices,fee);  //Approach-4 Tabulation With Space Optimization  
    return tabulationWithSpaceOptimization2(prices,fee);  //Approach-5 Tabulation With Space Optimization Using Variables 
    }
};
