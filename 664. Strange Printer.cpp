class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1)return dp[i][j] ;
        int partition = INT_MAX;
        //try all partition 
        for(int k=i;k<j;k++){
            partition = min(partition,solve(i,k,s,dp) + solve(k+1,j,s,dp)) ; 
        }

        if(s[i]==s[j]){
            partition--;
        }
        return dp[i][j] = partition;
    }
    int strangePrinter(string s) {
        //Partition DP
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,dp);
    }
};
