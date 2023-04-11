class Solution {
public:
     //Approach-1 Recursion Time Complexity: O(2^tar) [greater than it as we stay at ind after take operation] 
    // Space Complexity: O(100) [In worst case] and not O(tar) [as we stay at ind after take operation]
    int solve(int ind, int tar , vector<int>&sq){
        //Base Case:- If at ind 100 than we can only take 1 to form perfect squares
         if(ind==100){
            return tar;
        }

        int notTake = 0 + solve(ind+1,tar,sq);
        int take= 1e9; 

        //if possible to take (Infinte Supply Concept)
        if(sq[ind]<=tar){
            take=1+solve(ind,tar-sq[ind],sq);
        }
     //   cout<<tar<<"\n";
        return min(take,notTake);
    }

    //Approach-2 Memoization :- Time Complexity: O(N*100) Space Complexity: O(N*100) + O(100)
     int solve2(int ind, int tar , vector<int>&sq,vector<vector<int>>&dp){
        //Base Case:- If at ind 100 than we can only take 1 to form perfect squares
         if(ind==100){
            return tar;
        }

        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int notTake = 0 + solve2(ind+1,tar,sq,dp);
        int take= 1e9; 

        //if possible to take (Infinte Supply Concept)
        if(sq[ind]<=tar){
            take=1+solve2(ind,tar-sq[ind],sq,dp);
        }
     //   cout<<tar<<"\n";
        return dp[ind][tar] = min(take,notTake);
    }
    int numSquares(int n) { 
        //coin-change 1 similar problem

         vector<int>sq;
        for(int i=1;i<=100;i++){
            sq.push_back(i*i);
        }
        
        //return solve(0,n,sq); //Approach-1 Recursion
        
          vector<vector<int>>dp(101,vector<int>(10001,-1));
          return solve2(0,n,sq,dp); //Approach-2 Memoization
 
     }
};
