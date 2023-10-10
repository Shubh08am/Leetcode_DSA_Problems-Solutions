class Solution {
public:
    int solve(int ind1,int ind2,int x,vector<int>&pos,vector<vector<int>>&dp) {
        int cnt=pos.size();
         if(ind1>=ind2) return 0; 
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int ans=INT_MAX;
        //OPERATION -> 1 
        int op1=x+solve(ind1+1,ind2-1,x,pos,dp);
        //OPERATION -> 2 
        int op21 = pos[ind1+1]-pos[ind1]+solve(ind1+2,ind2,x,pos,dp);
        int op22 = pos[ind2]-pos[ind2-1]+solve(ind1,ind2-2,x,pos,dp);
        int op2=min(op21,op22);
        ans=min({ans,op1,op2});
        
        return dp[ind1][ind2]=ans;
    }
    int minOperations(string s1, string s2, int x) {
        //if odd times not equal not possible to make them equal 
        int cnt=0,n=s1.size(); 
        vector<int>pos;
        for(int i=0;i<n;i++) {if(s1[i]!=s2[i]) pos.push_back(i) ;} 
        cnt=pos.size();
        if(cnt&1) return -1 ; 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ; 
        return solve(0,cnt-1,x,pos,dp) ;
    }
};
