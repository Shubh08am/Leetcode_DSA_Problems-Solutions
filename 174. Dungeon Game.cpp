class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>& dp) {
        int n = dungeon.size() , m = dungeon[0].size() ; 
        if(i>n-1 || j>m-1) return 1e8;
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]>0) return 1; 
            return 1+abs(dungeon[i][j]);
        }
        if(dp[i][j]!=-1) return dp[i][j] ;

        int currReqHealth = dungeon[i][j] ;
        int down = solve(i+1,j,dungeon,dp) ; 
        int right = solve(i,j+1,dungeon,dp) ; 
        int nextReqHealth = min(down,right) ;
        
        int health = 0;
        //cout<<currReqHealth<<" "<<nextReqHealth<<"\n";

        //positive
        if(currReqHealth>=nextReqHealth){
            health=1;
        }
        //negative
        if(currReqHealth<nextReqHealth){
            health=nextReqHealth-currReqHealth;
        }
        return dp[i][j] = health ;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //agar last cell par pahuch gya > 0 se tho 1 
        //vrna 1+abs(curr) 
        int n = dungeon.size() , m = dungeon[0].size() ; 
        vector<vector<int>>dp(n,vector<int>(m,-1)) ; 
        return solve(0,0,dungeon,dp);
    }
};
