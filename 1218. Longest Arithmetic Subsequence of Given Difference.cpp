class Solution {
public:
    //  brute force -> o(n*n)
    int solve(int ind,int prev, int difference,vector<int>& arr,vector<vector<int>>&dp){
        int n = arr.size() ; 
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int notTake = 0+solve(ind+1,prev,difference,arr,dp) ; 
        int take = 0; 
        //if possible to take 
        if(prev==-1 || arr[ind]-arr[prev] == difference){
            take=1+solve(ind+1,ind,difference,arr,dp) ;
        }
    return dp[ind][prev+1]=max(take,notTake);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size() ;
       // vector<vector<int>>dp(n,vector<int>(n+1,-1));
      //  return solve(0,-1,difference,arr,dp) ;  

      // optimized -> o(n) -> dp+hashing 
       map<int,int>dp;
       int las=0;
       for(int i=0;i<n;i++){
           if(dp.find(arr[i]-difference) !=dp.end()){
               dp[arr[i]]=1+dp[arr[i]-difference];
           }
           else dp[arr[i]]=1;
           las=max(las,dp[arr[i]]);
       }
    return las;
    }
};
