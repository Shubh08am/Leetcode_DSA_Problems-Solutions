class Solution {
public:
    //APPROACH 1:- RECURSION Time Complexity :- O(2^N) Space Complexity :- O(N)
    long long int solve(long long int num){
        if(num==1){
            return 0;
        }
        long long int way = INT_MAX , bestWay = INT_MAX ;

        if(!(num&1)){
                way = 1 + solve(num>>1) ; 
                return way ; 
        }

        if(num&1){
            //EXPLORE BOTH WAYS AND TAKE MIN OF BOTH 
            long long int way1 = 1 + solve(num+1) ; 
            long long int way2 = 1 + solve(num-1) ; 
            bestWay = min(way1,way2) ; //Take min one
            return bestWay ;
        }
        
        return min(way,bestWay);
    }

    //APPROACH 2:- MEMOIZATION Time Complexity :- O(N) Space Complexity :- O(N) 
    //ONLY ONE STATE CHANGES AND THAT IS N (ITSELF)
    long long int solve2(long long int num,unordered_map<long long int,long long int>&dp){
        if(num==1){
            return 0;
        }
        long long int way = INT_MAX , bestWay = INT_MAX ;

        if(dp.find(num)!=dp.end()) return dp[num] ;

        if(!(num&1)){
                way = 1 + solve2(num>>1,dp) ; 
            //  return dp[num] = way ; //or take at last
        }

        if(num&1){
            //EXPLORE BOTH WAYS AND TAKE MIN OF BOTH 
            long long int way1 = 1 + solve2(num+1,dp) ; 
            long long int way2 = 1 + solve2(num-1,dp) ; 
            bestWay = min(way1,way2) ; //Take min one
         //   return dp[num] = bestWay ; //or take at last
        }
        
        return dp[num] = min(way,bestWay);
    }

    int integerReplacement(int n) {
     //  return solve(n); //Approach 1 - Recursion 

     unordered_map<long long int,long long int>dp; // 1-D DP Problem 
     return solve2(n,dp); //Approach 2 - Memoization
    }
};
