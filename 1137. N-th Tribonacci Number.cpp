class Solution {
public:
    int recursion(int n){
        if(n==0) return 0;
        if(n<=2&&n>0) return 1;
        return recursion(n-1)+recursion(n-2)+recursion(n-3);
    }
    int memoization(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n<=2&&n>0) return 1;
        if(dp[n]!=-1) return dp[n] ;
        return dp[n]=memoization(n-1,dp)+memoization(n-2,dp)+memoization(n-3,dp);
    }
    int tabulationSpaceOptimization(int n){
      //tabulation with space optimization 
        int prev1=0 , prev2=1 , prev3=1 ; 
        for(int i=3;i<=n;i++){
            int curr = prev3;
            prev3=prev3+prev2+prev1; 
            int curr2 = prev2;
            prev2=curr;
            prev1=curr2;
        }
        if(n==0) return 0;
        if(n<=2) return 1;
        return prev3;
    }
    int tribonacci(int n) {
     
    // return recursion(n);
    //  vector<int>dp(n+1,-1);
    //  return memoization(n,dp);

      return tabulationSpaceOptimization(n) ; 
    }
};
