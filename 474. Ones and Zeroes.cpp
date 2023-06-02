class Solution {
public:
    int dp[601][101][101];
    int solve(int i,vector<string>& strs, int m, int n){
        int x=strs.size();

        if(i==x) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        //count 0 & 1 
        int z_0=0,o_1=0;

        for(int j=0;j<strs[i].size();j++){
          //  cout<<strs[i]<<" ";
            z_0+=(strs[i][j]=='0') ; 
            o_1+=(strs[i][j]=='1') ;
        }

      //  cout<<z_0<<" "<<o_1<<"\n";

        //TAKE AND NOT TAKE 
        int notTake = solve(i+1,strs,m,n) ; 
 
        int take=INT_MIN ; 
         if(m>=z_0 && n>=o_1){
            take = 1+solve(i+1,strs,m-z_0,n-o_1) ;
        }
    return dp[i][m][n] =  max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,strs,m,n);
    }
};
