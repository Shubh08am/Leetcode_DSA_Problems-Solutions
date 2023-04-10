class Solution {
public:
    //Approach 1:- Recursion
    int solve(int n , int k){
         //base case:- when breaked into k part  
         if(k==0){
             return n;
         }
         //Now,break into k parts 
         int ans=1;
         for(int i=1;i<n;i++){
             //breaked into 1 i.e k reduces by 1 
             //and n decreases by i 
             ans=max(ans,i*solve(n-i,k-1));
         }
        return ans;
    }
    //Approach 2:- Memoization
        int solve2(int n , int k,vector<vector<int>>&dp){
         //base case:- when breaked into k part  
         if(k==0){
             return n;
         } 
         if(dp[n][k]!=-1)  return dp[n][k];

         //Now,break into k parts 
         int ans=1;
         for(int i=1;i<n;i++){
             //breaked into 1 i.e k reduces by 1 
             //and n decreases by i 
             ans=max(ans,i*solve2(n-i,k-1,dp));
         }
        return dp[n][k]=ans;
    }
    int integerBreak(int n) {
        //try all combination of breaking 
        int res=1; //atleast 1 answer 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=1;i<n;i++){
           // res=max(res,solve(n,i)); 
            res=max(res,solve2(n,i,dp)); 
        }
        return res;
    }
};
