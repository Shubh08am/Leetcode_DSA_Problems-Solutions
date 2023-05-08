class Solution {
public: 
    //Approach-1 Recursion Time Complexity: O(2^N)[Take,notTake] Space Complexity: O(N)[Auxillary Stack Space]
     int solve(int ind,int buy,int transaction,vector<int>&prices){
        int n = prices.size() , profit=0; 
        
        if(ind==n || transaction==0) return 0;

        //Buying Stock when buy = 1 
        if(buy){
            //take -> means we bought ind stock 
            //now,we can't buy untill we sell this stock. ThereFore, buy=0
            //notTake -> means we didn't bought ind stock 
            //now,we can buy other stock. ThereFore, buy=1
            int take = -prices[ind]+solve(ind+1,0,transaction,prices) ; 
            int notTake = 0+solve(ind+1,1,transaction,prices) ;
            profit = max(take,notTake);
        }
        //Selling Stock when buy = 0 
        else if(buy==0){
            //take -> means we sold ind stock 
            //now,we can buy stock. ThereFore, buy=1
            //notTake -> means we didn't sold ind stock 
            //now,we can't buy other stock. ThereFore, buy=0
            //After we sold the stock one transaction is done therefore transaction-1
            int take = prices[ind]+solve(ind+1,1,transaction-1,prices) ; 
            int notTake = 0+solve(ind+1,0,transaction,prices) ;
            profit = max(take,notTake);
        }
        return profit;
    }
//Approach-2 Memoization Time Complexity: O(N*2*3)[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states] 
// Space Complexity:O(N*2*3) + O(N) [O(N)[Auxillary Stack Space]]
    int solve2(int ind,int buy,int transaction,vector<int>&prices,vector<vector<vector<int>>>&dp){
            int n = prices.size() , profit=0; 
            if(ind==n || transaction==0) return 0;
            if(dp[ind][buy][transaction]!=-1) return dp[ind][buy][transaction];

            if(buy){
                int take = -prices[ind]+solve2(ind+1,0,transaction,prices,dp);
                int notTake = 0+solve2(ind+1,1,transaction,prices,dp);
                profit=max(take,notTake);
            }
            else{
                //transaction successfull after we sold the stock therefore transaction-1
                int take = prices[ind]+solve2(ind+1,1,transaction-1,prices,dp);
                int notTake = 0+solve2(ind+1,0,transaction,prices,dp);
                profit=max(take,notTake);
            }
           return dp[ind][buy][transaction]=profit;
    }
    //Approach-3 Tabulation Time Complexity: O(N*2*3)[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states] 
// Space Complexity:O(N*2*3)  
     int tabulation(vector<int>& prices){
            int n = prices.size(); 
            // Creating a 3d - dp of size [n+1][2][3] initialized to 0
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
           // BASE CASE:- if(ind==n || transaction==0) return 0; 
           //Although As dp array is intialized to 0, we have already covered the base case
             dp[n][0][0]=dp[n][0][1]= dp[n][0][2]=dp[n][1][0]=dp[n][1][1]= dp[n][1][2]=0;

            for(int ind=n-1;ind>=0;ind--){
                 // buy = 0 to 1 or buy = 1 to 0 -> both correct
             //   for(int buy=0;buy<=1;buy++){
                     for(int buy=1;buy>=0;buy--){
                // transaction = 0 to 2 or transaction = 2 to 0 -> both correct
              //      for(int transaction=0;transaction<=2;transaction++){
                   for(int transaction=2;transaction>=0;transaction--){
                        int profit=0;
                             if(buy){
                                     int take = -prices[ind]+dp[ind+1][0][transaction];
                                    int notTake = 0+dp[ind+1][1][transaction];
                                    profit=max(take,notTake);
                                 }
                            else{   
                                    //transaction successfull after we sold the stock therefore transaction-1
                                    int take = INT_MIN;
                                    if(transaction>0) take=prices[ind]+dp[ind+1][1][transaction-1];
                                    int notTake = 0+dp[ind+1][0][transaction];;
                                    profit=max(take,notTake);
                                 }
                              dp[ind][buy][transaction]=profit;
                    }
                }
            }
    return dp[0][1][2];//as Recursion Call from (0,1,2)
    }
      //Approach-4 Tabulation With Space Optimization Time Complexity: O(N*2*3)
      //[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states]  Space Complexity:O(1)  
     int tabulationWithSpaceOptimization(vector<int>& prices){
            int n = prices.size(); 
            vector<vector<int>>ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

            for(int ind=n-1;ind>=0;ind--){
                 for(int buy=0;buy<=1;buy++){
                    for(int transaction=0;transaction<=2;transaction++){
                        int profit=0;
                             if(buy){
                                     int take = -prices[ind]+ahead[0][transaction];
                                    int notTake = 0+ahead[1][transaction];
                                    profit=max(take,notTake);
                                 }
                            else{   
                                    //transaction successfull after we sold the stock therefore transaction-1
                                    int take = INT_MIN;
                                    if(transaction>0) take=prices[ind]+ahead[1][transaction-1];
                                    int notTake = 0+ahead[0][transaction];
                                    profit=max(take,notTake);
                                 }
                              curr[buy][transaction]=profit;
                    }
                }
                ahead=curr; //update 
            }
    return ahead[1][2];//as Recursion Call from (0,1,2)
    }
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        //transaction=2 , but=1 (can Buy) , ind=0

       // return solve(0,1,2,prices); //Approach-1 Recursion
       //dp[ind][buy][transaction]
      // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
     //  return solve2(0,1,2,prices,dp); //Approach-2 Memoization
    //  return tabulation(prices); //Approach-3 Tabulation 
     return tabulationWithSpaceOptimization(prices); //Approach-4 tabulation With Space Optimization
    } 
};
