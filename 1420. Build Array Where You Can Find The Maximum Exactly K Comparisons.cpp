class Solution {
public:
    const int mod = 1e9+7; 
    int solve(int prev_num,int n,int m,int k, vector<vector<vector<int>>>&dp){
        //if all n numbers found and search cost reduced to 0 possible premutation 
        if(n==0){
            return k==0;
        }
        //if at any moment search cost less than 0 not a possible premutation 
        if(k<0) return 0;

        if(dp[prev_num+1][n][k]!=-1) return dp[prev_num+1][n][k] ;
        int ways=0;
        //try all ways i.e from 1 to m 
        for(int curr_num=1;curr_num<=m;curr_num++){
            //Now,see when to reduce the search cost 
            if(curr_num>prev_num){
                //reduce search cost by 1 
                ways=(ways+solve(curr_num,n-1,m,k-1,dp))%mod;
            }
            if(curr_num<=prev_num){
                //not reducing search cost by 1 and prev_num remains as it is
                ways=(ways+solve(prev_num,n-1,m,k,dp))%mod;
            }
        }
    return dp[prev_num+1][n][k] = ways; 
    }
    int numOfArrays(int n, int m, int k) {
        // dp -> try all ways and take count of it 
        // 3 states -> curr_no i.e 1-m , for n ->till now how much no. , k -> till now search cost 
        vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+1,vector<int>(k+1,-1))) ; 
        //carry prev_num number start from 0 for comparing with curr_num and reduced search cost accordingly 
        return solve(-1,n,m,k,dp);

    }
};
