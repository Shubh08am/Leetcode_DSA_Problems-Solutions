class Solution {
public:
      //Approach-1 Recursion Time Complexity: O(2^N)[Take,notTake] Space Complexity: O(N)[Auxillary Stack Space]
    int solve(int ind,int buy,int cooldown,vector<int>&prices){
        int n=prices.size(),profit=0;

        if(ind>=n) return 0;
        if(cooldown>=n ) return 0;

        if(buy){
            int take=-prices[ind]+solve(ind+1,0,cooldown+1,prices);
            int notTake=0+solve(ind+1,1,cooldown+1,prices);
            profit=max(take,notTake);
        }
        else{
            int take = prices[ind]+solve(ind+2,1,cooldown+2,prices);
            int notTake = 0+solve(ind+1,0,cooldown+1,prices);
            profit=max(take,notTake);
        }
    return profit;
    }
//Approach-2 Memoization [Using 3d dp] Time Complexity: O(N*2*N)[buy->0 or 1 --> 2 states] [cooldown->0 to n --> n states] 
// Space Complexity:O(N*2*N) + O(N) [O(N)[Auxillary Stack Space]]
    int solve2(int ind,int buy,int cooldown,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n=prices.size(),profit=0;

        if(ind>=n) return 0;
        if(cooldown>=n ) return 0;

        if(dp[ind][buy][cooldown]!=-1) return dp[ind][buy][cooldown];
        if(buy){
            int take=-prices[ind]+solve2(ind+1,0,cooldown+1,prices,dp);
            int notTake=0+solve2(ind+1,1,cooldown+1,prices,dp);
            profit=max(take,notTake);
        }
        else{
            int take = prices[ind]+solve2(ind+2,1,cooldown+2,prices,dp);
            int notTake = 0+solve2(ind+1,0,cooldown+1,prices,dp);
            profit=max(take,notTake);
        }
    return dp[ind][buy][cooldown]=profit;
    }
    //Approach-2 Memoization [Using 2d dp] Time Complexity: O(N*2)[buy->0 or 1 --> 2 states] [cooldown->0 to n --> n states] 
// Space Complexity:O(N*2) + O(N) [O(N)[Auxillary Stack Space]]
    int solve3(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size(),profit=0;

        if(ind>=n) return 0;
 
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int take=-prices[ind]+solve3(ind+1,0,prices,dp);
            int notTake=0+solve3(ind+1,1,prices,dp);
            profit=max(take,notTake);
        }
        else{
            int take = prices[ind]+solve3(ind+2,1,prices,dp);
            int notTake = 0+solve3(ind+1,0,prices,dp);
            profit=max(take,notTake);
        }
    return dp[ind][buy]=profit;
    }
    //Approach-3 Tabulation Time Complexity: O(N*2*k)[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states] 
// Space Complexity:O(N*2*k)  
     int tabulation(vector<int>& prices){
            int n = prices.size(); 
            // Creating a 2d - dp of size [n+2][2] initialized to 0
            vector<vector<int>>dp(n+2,vector<int>(2,0));
           //  As dp array is intialized to 0, we have already covered the base case
 
            for(int ind=n-1;ind>=0;ind--){
                 // buy = 0 to 1 or buy = 1 to 0 -> both correct
              //  for(int buy=0;buy<=1;buy++){
                     for(int buy=1;buy>=0;buy--){
                        int profit=0;
                             if(buy){
                                     int take = -prices[ind]+dp[ind+1][0];
                                    int notTake = 0+dp[ind+1][1];
                                    profit=max(take,notTake);
                                 }
                            else{   
                                    //transaction successfull after we sold the stock therefore cooldown
                                    int take=prices[ind]+dp[ind+2][1];
                                    int notTake = 0+dp[ind+1][0];;
                                    profit=max(take,notTake);
                                 }
                              dp[ind][buy]=profit;
                }
            }
    return dp[0][1];//as Recursion Call from (0,1)
    }
    //Approach-4 Tabulation With Space Optimization Time Complexity: O(N*2)
      //[buy->0 or 1 --> 2 states]   Space Complexity:O(1)  
     int tabulationWithSpaceOptimization(vector<int>& prices){
            int n = prices.size(); 
            vector<int>curr(2,0),front1(2,0),front2(2,0);
            //dp[ind] -> curr 
            //dp[ind+1] -> front1
            //dp[ind+2] -> front2
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    if(buy){
                    curr[buy]=max(-prices[ind]+front1[0],0+front1[1]);
                }
                    else{
                        curr[buy]=max(prices[ind]+front2[1],0+front1[0]);
                    }
            }
            //update
             front2=front1;
             front1=curr;
    }
    return curr[1];
    }
     //Approach-4 Tabulation With Space Optimization Time Complexity: O(N)   Space Complexity:O(1)  
     int tabulationWithSpaceOptimization2(vector<int>& prices){
            int n = prices.size(); 
            vector<int>curr(2,0),front1(2,0),front2(2,0);
            //dp[ind] -> curr 
            //dp[ind+1] -> front1
            //dp[ind+2] -> front2

            //Eliminating buy loop 
            for(int ind=n-1;ind>=0;ind--){
                //At a time one is executed as buy keeps changing from 0 to 1 or 1 to 0
                     curr[1]=max(-prices[ind]+front1[0],0+front1[1]);
                     curr[0]=max(prices[ind]+front2[1],0+front1[0]);
             //update
             front2=front1;
             front1=curr;
    }
    return curr[1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //return solve(0,1,0,prices);//Approach-1 Recursion

        //3d dp :-//dp[ind][buy][cooldown]
       // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(n,-1)));
       // return solve2(0,1,0,prices,dp); //Approach-2 Memoization

        //2d dp :-//dp[ind][buy]
      //  vector<vector<int>>dp(n,vector<int>(2,-1));
      //  return solve3(0,1,prices,dp); //Approach-2 Memoization
     //  return tabulation(prices); //Approach-3 Tabulation 
    // return tabulationWithSpaceOptimization(prices) ; //Approach-4 tabulation With Space Optimization
      return tabulationWithSpaceOptimization2(prices) ; //Approach-4 tabulation With Space Optimization
    }
};
