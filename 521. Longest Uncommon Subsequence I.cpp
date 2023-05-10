class Solution {
public:
    int findLUSlength(string a, string b) {
       //N-SCS[shortest Common Subsequence]
       int n=a.size() , m=b.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0)); 


     for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //match
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                //not match
                else if(a[i-1]!=b[i-1])  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
     }
     int LUS = max(n,m)-dp[n][m] ;
     return LUS==0?-1:max({n,m,dp[n][m]}) ; 
    }
};
