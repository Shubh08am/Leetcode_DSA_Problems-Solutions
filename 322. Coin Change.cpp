class Solution {
public:
     //Approach-1 Recursion Time Complexity: O(2^N) [greater than it as we stay at ind after take operation] 
    // Space Complexity: O(amount) [In worst case] and not O(N) [as we stay at ind after take operation]
    int solve(int ind,vector<int>& coins, int amount){
         int n = coins.size();
          //when amount exhausted 
           if(ind==n-1){
              //if by using that last coin amount can be exhausted 
              if(amount%coins[n-1]==0) return amount/coins[n-1];
              return 1e9;
          }
          //Explore all the ways 
          int take=1e9;
          int  notTake = 0 + solve(ind+1,coins,amount) ; 
          //as taking 1 coin therefore add 1 and stay at ind position only as we may use it again on reduced target
              if(coins[ind]<=amount) take = 1+ solve(ind,coins,amount-coins[ind]) ; 
           return  min(take,notTake) ;
    }
     //Approach-2 Memoization :- Time Complexity: O(N*amount) Space Complexity: O(N*amount) + O(amount)
    int solve2(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
         int n = coins.size();
          //when amount exhausted 
           if(ind==n-1){
              //if by using that last coin amount can be exhausted 
              if(amount%coins[n-1]==0) return amount/coins[n-1];
              return 1e9;
          } 
            if(dp[ind][amount]!=-1)  return dp[ind][amount] ; 
          //Explore all the ways 
          int take=1e9;
          int notTake = 0 + solve2(ind+1,coins,amount,dp) ; 
          //as taking 1 coin therefore add 1 and stay at ind position only as we may use it again on reduced target
              if(coins[ind]<=amount) take = 1+ solve2(ind,coins,amount-coins[ind],dp) ; 
           return dp[ind][amount] = min(take,notTake) ;
    }
     //Approach-3 Tabulation :- Time Complexity: O(N*amount) Space Complexity: O(N*amount)
    int tabulation(vector<int>& coins, int amount){
         int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
         //Recursion call from(0,amount) i.e tabulation from ind = n-1(base-case [bottom]) to 0([Up]) & target = 0 to target

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             if(tar%coins[n-1]==0) dp[n-1][tar] = tar/coins[n-1];
             else dp[n-1][tar] = 1e9 ;
         }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    int notTake = 0 + dp[ind+1][tar] ;
                    int take = 1e9 ; 
                    //as taking 1 coin therefore add 1 and stay at ind position only as we may use it again on reduced target
                    if(coins[ind]<=tar) take = 1 + dp[ind][tar-coins[ind]] ; 

                    dp[ind][tar] = min(take,notTake) ;
             }
        }
        return dp[0][amount] ;//as Recursion call from(0,amount)
    }
     //Approach-4 Tabulation with Space Optimization  :- Time Complexity: O(N*amount) Space Complexity: O(amount)
    int tabulationWithSpaceOptimization(vector<int>& coins, int amount){
         int n = coins.size();
         vector<int>prev(amount+1,0),curr(amount+1,0);

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             if(tar%coins[n-1]==0) prev[tar] = tar/coins[n-1];
             else prev[tar] = 1e9 ;
         }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    int notTake = 0 + prev[tar] ;
                    int take = 1e9 ; 
                    //as taking 1 coin therefore add 1 and stay at ind position only as we may use it again on reduced target
                    //since,at position=ind we use curr and not prev
                    if(coins[ind]<=tar) take = 1 + curr[tar-coins[ind]] ; 

                    curr[tar] = min(take,notTake) ;
             }
             prev=curr;
        }
        return prev[amount] ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
     //   int coin = solve(0,coins,amount) ;
     //   return  coin==1e9?-1:coin ; //Approach-1 Recursion

    //    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //   int coin2 = solve2(0,coins,amount,dp);
    //    return coin2==1e9?-1:coin2 ; //Approach-2 Memoization
   
    //  int coin3 = tabulation(coins,amount);
    //  return coin3==1e9?-1:coin3 ; //Approach-3 Tabulation

       int coin4 = tabulationWithSpaceOptimization(coins,amount);
       return coin4==1e9?-1:coin4 ; //Approach-4 tabulationWithSpaceOptimization
    }
};
