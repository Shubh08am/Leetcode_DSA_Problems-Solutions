class Solution {
public:
    int LCS(string a , string b){
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m]==n;
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;

        for(int i=0 ; i<n ; i++){
            bool flag = true;
            string a=strs[i];
            for(int j=0 ; j<n ; j++){
                 string b=strs[j];
                   if(i!=j && LCS(a,b)){
                    flag = false;
                    break;
                }
            }
            if(flag) ans = max(ans , (int)a.size());
        }
        return ans;
    }
};
