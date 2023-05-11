class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //LCS VARIATION
        int n=nums1.size(),m=nums2.size(); 
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
         int i=1;
         while(i<=n){
            int j=1;
            while(j<=m){
                //match 
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                //not-match
                else if(nums1[i-1]!=nums2[j-1]) dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                j++;
            }
        i++;
        }
        return dp[n][m];
    }
};
