class Solution {
public:
    int dp[101][101][101]; 
    int solve(int ind,int p1,int p2,vector<vector<int>>& costs){
        int n=costs.size();
        if(ind==n){
            if(p1==n/2 && p2==n/2) return 0;
            else return 1e8;
        }
        if(dp[ind][p1][p2]!=-1) return dp[ind][p1][p2]; 
        int take_a = costs[ind][0] + solve(ind+1,p1+1,p2,costs) ; 
        int take_b = costs[ind][1] + solve(ind+1,p1,p2+1,costs) ; 
    return dp[ind][p1][p2] = min(take_a,take_b);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
      // costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]] 
      // A -> 184+259+577 B->54+667+118 -> 1859 
        memset(dp,-1,sizeof(dp)) ; 
        return solve(0,0,0,costs);
    }
};
