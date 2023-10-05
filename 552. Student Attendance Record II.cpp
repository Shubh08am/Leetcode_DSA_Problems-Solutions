class Solution {
public:
    const int mod = 1e9+7;
    int solve(int ind,int n,int Absent,int Late,vector<vector<vector<int>>>&dp){
        if(ind==n){
            return 1;
        }
        if(dp[ind][Absent][Late]!=-1) return dp[ind][Absent][Late] ; 

        int totalWays=0;
        //CASE - 1 NOT ABSENT AS OF NOW -> THUS CONSIDER LATE , ABSENT AND PRESENT 
        if(Absent==0){
            int present = solve(ind+1,n,0,0,dp); //ALL PRESENT CASE -> LATE=0
            int absent = solve(ind+1,n,1,0,dp); //1 ABSENT CASE -> LATE=0
            int late=0; 
            //Consecutive max 2 days late 
            if(Late<2){
                late=solve(ind+1,n,0,Late+1,dp);// LATE CASE 
            }
            totalWays=((present+absent)%mod+late)%mod;
        }
        //CASE - 2 ALREADY ABSENT -> THUS CONSIDER LATE , PRESENT ONLY
        if(Absent==1){
            int present = solve(ind+1,n,1,0,dp);
            int late=0; 
            //Consecutive max 2 days late 
            if(Late<2){
                late=solve(ind+1,n,1,Late+1,dp);
            }
            totalWays=(present+late)%mod;
        }
    return dp[ind][Absent][Late]=totalWays; 
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1))) ; 
        return solve(0,n,0,0,dp);
    }
};
