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
    //Approach-2 Memoization Time Complexity: O(N*2*k)[buy->0 or 1 --> 2 states] [transaction->0 to k --> k states] 
// Space Complexity:O(N*2*k) + O(N) [O(N)[Auxillary Stack Space]]
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
 //Approach-3 Tabulation Time Complexity: O(N*2*k)[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states] 
// Space Complexity:O(N*2*k)  
     int tabulation(vector<int>& prices,int k){
            int n = prices.size(); 
            // Creating a 3d - dp of size [n+1][2][k+1] initialized to 0
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
           // BASE CASE:- if(ind==n || transaction==0) return 0; 
           //  As dp array is intialized to 0, we have already covered the base case
 
            for(int ind=n-1;ind>=0;ind--){
                 // buy = 0 to 1 or buy = 1 to 0 -> both correct
                for(int buy=0;buy<=1;buy++){
                //     for(int buy=1;buy>=0;buy--){
                // transaction = 0 to k or transaction = k to 0 -> both correct
                    for(int transaction=0;transaction<=k;transaction++){
              //     for(int transaction=k;transaction>=0;transaction--){
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
    return dp[0][1][k];//as Recursion Call from (0,1,k)
    }
     //Approach-4 Tabulation With Space Optimization Time Complexity: O(N*2*k)
      //[buy->0 or 1 --> 2 states] [transaction->0 to k --> k states]  Space Complexity:O(1)  
     int tabulationWithSpaceOptimization(vector<int>& prices,int k){
            int n = prices.size(); 
            vector<vector<int>>ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));

            for(int ind=n-1;ind>=0;ind--){
                 for(int buy=0;buy<=1;buy++){
                    for(int transaction=0;transaction<=k;transaction++){
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
    return ahead[1][k];//as Recursion Call from (0,1,k)
    }
    //Approach-5 Recursion Time Complexity: Exponential Space Complexity: O(N)[Auxillary Stack Space]
    //Using N*K Method Now 
    int solve4(int ind,int tranNo,int k,vector<int>&prices){
         int n = prices.size(),profit=0;
          //2*k as 2 operations -> Buy and Sell for each transaction
        if(ind==n || tranNo==2*k) return 0;

        //when even tranNo we buy stock
        if(tranNo%2==0){
            //as we buy we go to next transaction
            int take = -prices[ind]+solve4(ind+1,tranNo+1,k,prices) ; 
            int notTake = 0+solve4(ind+1,tranNo,k,prices) ;
            profit = max(take,notTake);
        }
        //when odd tranNo we sell stock 
       else  if(tranNo%2!=0) {
            //as we sell we go to next transaction
            int take = prices[ind]+solve4(ind+1,tranNo+1,k,prices) ; 
            int notTake = 0+solve4(ind+1,tranNo,k,prices) ;
            profit = max(take,notTake);
        }
        return profit;
    }
 //Approach-6 Memoization Time Complexity: O(N*2*k)[buy->0 or 1 --> 2 states] [transaction->0 to k --> k states] 
// Space Complexity:O(N*2*k) + O(N) [O(N)[Auxillary Stack Space]]
    int solve5(int ind,int tranNo,int k,vector<int>&prices,vector<vector<int>>&dp){
         int n = prices.size(),profit=0;
         //2*k as 2 operations -> Buy and Sell for each transaction 
        if(ind==n || tranNo==2*k) return 0;
        if(dp[ind][tranNo]!=-1) return dp[ind][tranNo];
        //when even tranNo we buy stock
        if(tranNo%2==0){
            //as we buy we go to next transaction
            int take = -prices[ind]+solve5(ind+1,tranNo+1,k,prices,dp) ; 
            int notTake = 0+solve5(ind+1,tranNo,k,prices,dp) ;
            profit = max(take,notTake);
        }
        //when odd tranNo we sell stock 
       else  if(tranNo%2!=0) {
            //as we sell we go to next transaction
            int take = prices[ind]+solve5(ind+1,tranNo+1,k,prices,dp) ; 
            int notTake = 0+solve5(ind+1,tranNo,k,prices,dp) ;
            profit = max(take,notTake);
        }
        return dp[ind][tranNo]= profit;
    }
//Approach-7 Tabulation Time Complexity: O(N*2*k)[buy->0 or 1 --> 2 states] [transaction->0 or 1 or 2 --> 3 states] 
// Space Complexity:O(N*2*k)  
     int tabulation2(vector<int>& prices,int k){
            int n = prices.size(); 
            // Creating a 2d - dp of size [n+1][2*k+1] initialized to 0
             vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
            //  As dp array is intialized to 0, we have already covered the base case
 
            for(int ind=n-1;ind>=0;ind--){
                 // as for tranNo = 2*k  we return 0 [base case]
                 //thus,starting tranNo from 2*k-1 to 0 
                    for(int tranNo=2*k-1;tranNo>=0;tranNo--){
                        int profit=0;
                          //when even tranNo we buy stock
                                    if(tranNo%2==0){
                                        //as we buy we go to next transaction
                                        int take = -prices[ind]+dp[ind+1][tranNo+1] ; 
                                        int notTake = 0+dp[ind+1][tranNo] ;
                                        profit = max(take,notTake);
                                    }
                                    //when odd tranNo we sell stock 
                                    else  if(tranNo%2!=0) {
                                        //as we sell we go to next transaction
                                        int take = prices[ind]+dp[ind+1][tranNo+1] ;
                                        int notTake = 0+dp[ind+1][tranNo] ;
                                        profit = max(take,notTake);
                                    }
                                    dp[ind][tranNo]= profit;
                }
            }
    return dp[0][0];//as Recursion Call from (0,0)
    }
//Approach-8 Tabulation With Space Optimization Time Complexity: O(N*2*k)
      //[buy->0 or 1 --> 2 states] [transaction->0 to k --> k states]  Space Complexity:O(2*k)
      int tabulationWithSpaceOptimization2(vector<int>& prices,int k){
            int n = prices.size(); 
              vector<int>ahead(2*k+1,0),curr(2*k+1,0);
  
            for(int ind=n-1;ind>=0;ind--){
                 // as for tranNo = 2*k  we return 0 [base case]
                 //thus,starting tranNo from 2*k-1 to 0 
                    for(int tranNo=2*k-1;tranNo>=0;tranNo--){
                        int profit=0;
                          //when even tranNo we buy stock
                                    if(tranNo%2==0){
                                        //as we buy we go to next transaction
                                        int take = -prices[ind]+ahead[tranNo+1] ; 
                                        int notTake = 0+ahead[tranNo] ;
                                        curr[tranNo] = max(take,notTake);
                                    }
                                    //when odd tranNo we sell stock 
                                    else  if(tranNo%2!=0) {
                                        //as we sell we go to next transaction
                                        int take = prices[ind]+ahead[tranNo+1] ;;
                                        int notTake = 0+ahead[tranNo] ;
                                        curr[tranNo] = max(take,notTake);
                                    }
                 }
                 ahead=curr; //update
            }
    return ahead[0];//as Recursion Call from (0,0)
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //transaction=k , but=1 (can Buy) , ind=0

       // return solve(0,1,k,prices); //Approach-1 Recursion
       //dp[ind][buy][transaction]
     // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
      // return solve2(0,1,k,prices,dp); //Approach-2 Memoization
     //  return tabulation(prices,k); //Approach-3 Tabulation 
     //   return tabulationWithSpaceOptimization(prices,k); //Approach-4 tabulation With Space Optimization

     //  return solve4(0,0,k,prices); //Approach-5 Recursion
      //dp[ind][tranNo]
     // vector<vector<int>>dp(n,vector<int>(2*k,-1));
    //   return solve5(0,0,k,prices,dp); //Approach-6 Memoization
   //   return tabulation2(prices,k); //Approach-7 Tabulation
    return tabulationWithSpaceOptimization2(prices,k); //Approach-8 tabulation With Space Optimization
    }
};
