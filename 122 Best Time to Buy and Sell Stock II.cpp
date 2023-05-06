class Solution {
public:
    //APPROACH 1:-  PEAK VALLEY APPROACH (PEAK -> HIGHEST POINT) (VALLEY -> LOWEST POINT)
    // consider every peak immediately after a valley and take difference of peak and valley in profit 
    int peakValley(vector<int>&prices){
       int n = prices.size();
       int peak = prices[0] ;
       int valley = prices[0] ; 
       int profit=0;

       // peak -> prices[i]>prices[i+1] 
       // valley -> prices[i]<prices[i+1] 
        
        int i=0;
      while(i<n-1){
         //for valley 
          while(i<n-1 && prices[i]>=prices[i+1]) i++;
          valley = prices[i] ; 
       
         //for peak 
          while(i<n-1 && prices[i]<=prices[i+1]) i++;
          peak = prices[i] ; 
       
          profit+=(peak-valley);
      }
      return profit;
    }
    //APPROACH 2:-  PEAK VALLEY APPROACH EXTENSION 
    int peakValleyExtension(vector<int>&prices){
      int n = prices.size();
      int profit=0;

      for(int i=0;i<n-1;i++){
          int currProfit = prices[i+1] - prices[i] ; 
          int isProfitable = max(0,currProfit);
          profit+=isProfitable;
      }
      return profit;
    }
    //Approach-3 Recursion Time Complexity: O(2^N)[Take,notTake] Space Complexity: O(N)[Auxillary Stack Space]
    int solve(int ind,int buy,vector<int>&prices){
        int n = prices.size() , profit=0; 

        if(ind==n) return 0;
        
        //Buying Stock when buy = 1 
        if(buy){
            //take -> means we bought ind stock 
            //now,we can't buy untill we sell this stock. ThereFore, buy=0
            //notTake -> means we didn't bought ind stock 
            //now,we can buy other stock. ThereFore, buy=1
            int take = -prices[ind]+solve(ind+1,0,prices) ; 
            int notTake = 0+solve(ind+1,1,prices) ;
            profit = max(take,notTake);
        }
        //Selling Stock when buy = 0 
        else if(buy==0){
            //take -> means we sold ind stock 
            //now,we can buy stock. ThereFore, buy=1
            //notTake -> means we didn't sold ind stock 
            //now,we can't buy other stock. ThereFore, buy=0
            int take = prices[ind]+solve(ind+1,1,prices) ; 
            int notTake = 0+solve(ind+1,0,prices) ;
            profit = max(take,notTake);
        }

        return profit;
    }
    //Approach-4 Memoization Time Complexity: O(N*2)[buy->0 or 1 --> 2 states] Space Complexity:O(N*2) + O(N) [O(N)[Auxillary Stack Space]]
    int solve2(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        int n = prices.size() , profit=0; 

        if(ind==n) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy] ; 
        //Buying Stock when buy = 1 
        if(buy){
            //take -> means we bought ind stock 
            //now,we can't buy untill we sell this stock. ThereFore, buy=0
            //notTake -> means we didn't bought ind stock 
            //now,we can buy other stock. ThereFore, buy=1
            int take = -prices[ind]+solve2(ind+1,0,prices,dp) ; 
            int notTake = 0+solve2(ind+1,1,prices,dp) ;
            profit = max(take,notTake);
        }
        //Selling Stock when buy = 0 
        else if(buy==0){
            //take -> means we sold ind stock 
            //now,we can buy stock. ThereFore, buy=1
            //notTake -> means we didn't sold ind stock 
            //now,we can't buy other stock. ThereFore, buy=0
            int take = prices[ind]+solve2(ind+1,1,prices,dp) ; 
            int notTake = 0+solve2(ind+1,0,prices,dp) ;
            profit = max(take,notTake);
        }

        return dp[ind][buy] =  profit;
    }
    //Approach-5 Tabulation :- Time Complexity: O(N*2) Space Complexity: O(N*2)
    int tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0)) ; 
        //for base case :- if(ind==n )return 0 ; -> buy can be 0 or 1
        dp[n][0] = dp[n][1] = 0 ;

        //Changing states 
        for(int ind=n-1;ind>=0;ind--){
            // buy = 0 to 1 or buy = 1 to 0 -> both correct
            //for(int buy=0;buy<=1;buy++){
                 for(int buy=1;buy>=0;buy--){
                int profit=0;
                if(buy==1){
                    int take = -prices[ind]+dp[ind+1][0] ; //buy 
                    int notTake = 0+dp[ind+1][1]; //not buy -> buy further
                    profit = max(take,notTake);
                }
                else if(buy==0){
                    int take = prices[ind]+dp[ind+1][1] ; //sell -> now we can buy 
                    int notTake = 0+dp[ind+1][0]; //not sell -> not buy
                    profit = max(take,notTake);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];//as Recursion Call from (0,1)
    }
    //Approach-6 tabulation With Space Optimization :- Time Complexity: O(N*2) Space Complexity: O(1)
    int tabulationWithSpaceOptimization(vector<int>& prices){
        int n = prices.size();
        //ind      n-1  n
        //(buy=0)  |    |
        //(buy=1)  |    |
        //        curr ahead
        vector<int>ahead(2,0),curr(2,0) ; 
        //for base case :- if(ind==n )return 0 ; -> buy can be 0 or 1
        ahead[0] = ahead[1] = 0 ;

        //Changing states 
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy==1){
                    //dp[ind+1][buy]-> ahead[buy]
                    //dp[ind][buy] -> curr[buy] 
                    int take = -prices[ind]+ahead[0] ; //buy 
                    int notTake = 0+ahead[1]; //not buy -> buy further
                    profit = max(take,notTake);
                }
                else if(buy==0){
                    int take = prices[ind]+ahead[1] ; //sell -> now we can buy 
                    int notTake = 0+ahead[0]; //not sell -> not buy
                    profit = max(take,notTake);
                }
                curr[buy]=profit;
            }
            ahead=curr;//update
        }
        return ahead[1];//as Recursion Call from (0,1)
    }
     //Approach-7 tabulation With Space Optimization Using Variables :- Time Complexity: O(N*2) Space Complexity: O(1)
    int tabulationWithSpaceOptimization2(vector<int>& prices){
        int n = prices.size();
        
        //for base case :- if(ind==n )return 0 ; -> buy can be 0 or 1
        int aheadBuy = 0 ,  aheadNotBuy = 0 ;
         int currBuy ,  currNotBuy  ;

        //Changing states 
        for(int ind=n-1;ind>=0;ind--){
                      //ahead[0]-> aheadNotBuy
                    //ahead[1] -> aheadBuy 

                    //curr[0] -> currNotBuy
                    //curr[1] -> currBuy

                    //CASE FOR BUY=1
                    int take = -prices[ind]+aheadNotBuy ; //buy 
                    int notTake = 0+aheadBuy; //not buy -> buy further
                    currBuy =max(take,notTake);

                    //CASE FOR BUY=0
                    int take2 = prices[ind]+aheadBuy ; //sell -> now we can buy 
                    int notTake2 = 0+aheadNotBuy; //not sell -> not buy
                    currNotBuy =max(take2,notTake2);

            //update step like ahead=curr one 
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
         }
        return aheadBuy;//as Recursion Call from (0,1)
    }
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
      // return peakValley(prices); //APPROACH 1:-  PEAK VALLEY APPROACH
     //  return peakValleyExtension(prices); //APPROACH 2:-  PEAK VALLEY APPROACH EXTENSION
     
     //START WITH BUY=1 AS FIRST WE WANT TO BUY A STOCK THAN ONLY SELL IT
     //    return solve(0,1,prices); //Approach-3 Recursion
        
       //  vector<vector<int>>dp(n,vector<int>(2,-1)); 
       //  return solve2(0,1,prices,dp); //Approach-4 Memoization
       //return tabulation(prices); //Approach-5 Tabulation 
      //return tabulationWithSpaceOptimization(prices); //Approach-6 tabulation With Space Optimization
      return tabulationWithSpaceOptimization2(prices); //Approach-7 tabulation With Space Optimization Using Variables
    }
};
