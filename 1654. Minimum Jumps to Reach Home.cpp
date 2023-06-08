class Solution {
public:
    long long  f(int position , int jump_back,set<int> &forb,int a, int b, int x, vector<vector<long long >> &dp){
         
         if( position == x ) return 0;
         if(position <0 || position>6000) return 1e9;
         if(forb.count(position)) return 1e9;
         if(dp[position][jump_back]!=-1) return dp[position][jump_back];
         long long  steps_backword=1e9,steps_forward=1e9;
         dp[position][jump_back]=1+f(position+a,0,forb,a,b,x,dp);
         if(jump_back==0){
           dp[position][jump_back]=min(1+f(position-b,1,forb,a,b,x,dp),dp[position][jump_back]);
         }
         return dp[position][jump_back];     
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<vector<long long >>dp(6005,vector<long long>(2,-1));
        set<int> forb;
        for(auto it: forbidden) forb.insert(it);
        long long x1= f(0,1,forb,a,b,x,dp);
        return x1>=1e9? -1: x1;
    }
};
