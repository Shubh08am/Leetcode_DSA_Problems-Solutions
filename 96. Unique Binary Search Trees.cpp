class Solution {
public:
    //APPROACH 1 :- RECURSION T.C -> EXPONENTIAL 
    int dfs(int n){
        if(n<=1) return 1;
        int ans= 0; 

        for(int i=1;i<=n;i++) ans+= dfs(i-1)*dfs(n-i);
    
    return ans;
    }
    //APPROACH-2 MEMOIZATION T.C -> O(N^2) 
     int dfs2(int n,vector<int>&dp){
        if(n<=1) return 1;
        int ans= 0; 
        if(dp[n]!=-1) return dp[n] ;
        for(int i=1;i<=n;i++) ans+= dfs2(i-1,dp)*dfs2(n-i,dp);
    
    return dp[n] = ans;
    }
    //APPROACH -3 TABULATION 
    int tabulation(int n){
        vector<int>dp(n+1,0) ; 
        dp[0]=dp[1]=1; 

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++)
            dp[i]+= dp[j-1] * dp[i-j] ;
        }
    return dp[n] ;
    }
    int numTrees(int n) {
        // one node picked as root node 
        // i-1 node on left sub-tree 
        // n-i node on right sub-tree 
        // base case - null i.e 0 or single node is itself a bst 
       
       // return dfs(n);
      
      //  vector<int>dp(n+1,-1);
      //  return dfs2(n,dp);

      return tabulation(n);
    }
};
