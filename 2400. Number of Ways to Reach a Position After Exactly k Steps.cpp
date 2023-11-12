class Solution {
public:
    const int mod = 1e9+7;   
    vector<vector<int>>dp;
    int solve(int startPos, int endPos, int k) {
        if(k<0) return 0;
        if(startPos==endPos && k==0){
            return 1;
        }
        if(dp[startPos+1000][k]!=-1) return dp[startPos+1000][k];
        int right = solve(startPos+1,endPos,k-1);
        int left = solve(startPos-1,endPos,k-1); 
      //  cout<<startPos<< " "<< endPos << " "<< left+right<< "\n";
        return dp[startPos+1000][k]=(right+left)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        // dp+comibnatorics
        //states -> curr_pos & curr_step for k 
        dp.resize(startPos+2001,vector<int>(k+1,-1));
        return solve(startPos,endPos,k);
    }
};
