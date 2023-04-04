class Solution {
public:
     //Approach-1 Recursion Time Complexity: O(2^N) [greater than it as we stay at ind after take operation] 
    // Space Complexity: O(amount) [In worst case] and not O(N) [as we stay at ind after take operation]
    int solve(int ind,vector<int>& coins, int amount){
         int n = coins.size();
          //when amount exhausted 
           if(ind==n-1){
              //if by using that last coin amount can be exhausted 
              //its possible therefore return 1 else not Possible
              return (amount%coins[n-1]==0) ;
          }
          //Explore all the ways 
          int take=0;
          int  notTake = solve(ind+1,coins,amount) ; 
          //stay at ind position only as we may use it again on reduced target
              if(coins[ind]<=amount) take = solve(ind,coins,amount-coins[ind]) ; 
           return take+notTake ;
    }
     //Approach-2 Memoization :- Time Complexity: O(N*amount) Space Complexity: O(N*amount) + O(amount)
    int solve2(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
         int n = coins.size();
          //when amount exhausted 
           if(ind==n-1){
             //if by using that last coin amount can be exhausted 
              //its possible therefore return 1 else not Possible
              return (amount%coins[n-1]==0) ;
          } 
            if(dp[ind][amount]!=-1)  return dp[ind][amount] ; 
          //Explore all the ways 
          int take=0;
          int notTake = solve2(ind+1,coins,amount,dp) ; 
         //stay at ind position only as we may use it again on reduced target
          //INFINITE SUPPLY LOGIC :- STAY  AT SAME INDEX
              if(coins[ind]<=amount) take = solve2(ind,coins,amount-coins[ind],dp) ; 
           return dp[ind][amount] = take+notTake;
    }
     //Approach-3 Tabulation :- Time Complexity: O(N*amount) Space Complexity: O(N*amount)
    int tabulation(vector<int>& coins, int amount){
         int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
         //Recursion call from(0,amount) i.e tabulation from ind = n-1(base-case [bottom]) to 0([Up]) & target = 0 to target

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             dp[n-1][tar] =(tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    int notTake = dp[ind+1][tar] ;
                    int take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                    if(coins[ind]<=tar) take =dp[ind][tar-coins[ind]] ; 

                    dp[ind][tar] = take+notTake ;
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
             prev[tar] = (tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    int notTake = prev[tar] ;
                    int take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                    //since,at position=ind we use curr and not prev
                    if(coins[ind]<=tar) take =curr[tar-coins[ind]] ; 

                    curr[tar] = take+notTake;
             }
             prev=curr;
        }
        return prev[amount] ;
    }
//Approach-5 Tabulation with Space Optimization[Using Single Array]  :- Time Complexity: O(N*amount) Space Complexity: O(amount)
    int tabulationWithSpaceOptimization2(vector<int>& coins, int amount){
         int n = coins.size();
         vector<int>prev(amount+1,0);

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             prev[tar] =(tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    int notTake = prev[tar] ;
                    int take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                     
                    if(coins[ind]<=tar) take = prev[tar-coins[ind]] ; 
               
               //overwrite curr value in prev as for calculating curr[ind] 
               //we don't need left guy of prev[ind] only same column guy of curr[ind] i.e prev[ind]
               //thus,all left value from prev[ind] is not used therefore we can directly update
                    prev[tar] =  take+notTake;
             }
        }
        return prev[amount] ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
      //   int coin = solve(0,coins,amount) ;
      //   return coin ; //Approach-1 Recursion

      //  vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      // int coin2 = solve2(0,coins,amount,dp);
     //   return coin2 ; //Approach-2 Memoization
   
     // int coin3 = tabulation(coins,amount);
     //  return coin3 ; //Approach-3 Tabulation

     //  int coin4 = tabulationWithSpaceOptimization(coins,amount);
     //  return coin4 ; //Approach-4 tabulationWithSpaceOptimization

       int coin5 = tabulationWithSpaceOptimization(coins,amount);
       return coin5 ; //Approach-5 tabulationWithSpaceOptimization[Single array Used]
    }
};
