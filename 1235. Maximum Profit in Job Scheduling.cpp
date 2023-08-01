class Solution {
public:
    int bs(int low,vector<pair<int,pair<int,int>>>&vp,int val){
        int high = vp.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(vp[mid].first >= val){
                high=mid-1;
            }
            else low=mid+1;
        }
    return low;
    }
    int solve(int ind,vector<pair<int,pair<int,int>>>&vp,vector<int>&dp){
         int n = vp.size() ; 
         if(ind==n) return 0; 
         if(dp[ind]!=-1) return dp[ind] ; 
         int notTake = solve(ind+1,vp,dp) ; 
        //next pos where start time > end time 
         int posValid =  bs(ind,vp,vp[ind].second.first); 
        int take =  vp[ind].second.second + solve(posValid,vp,dp) ; 
        return dp[ind] = max(take,notTake) ; 
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // DP+BS
        int n = profit.size() ; 
        vector<int>dp(n,-1);
        vector<pair<int,pair<int,int>>>vp; 
        for(int i=0;i<n;i++){
            vp.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(vp.begin(),vp.end()) ; 
        return solve(0,vp,dp) ; 
    }
};
