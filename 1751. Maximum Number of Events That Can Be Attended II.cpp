class Solution {
public:
    int bs(int val,int low,vector<vector<int>>& events){
        int high=events.size()-1,ans=events.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>val){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
    return ans;
    }
    int solve(int ind,vector<vector<int>>& events, int k,vector<vector<int>>&dp){
        int n = events.size();
        if(ind>=n || k==0) return 0; 
        if(dp[ind][k]!=-1) return dp[ind][k] ; 
        int notTake=solve(ind+1,events,k,dp);
        int pos = bs(events[ind][1],ind,events);
        int take=events[ind][2]+solve(pos,events,k-1,dp);
        return dp[ind][k]=max(take,notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        //DP+BS 
        sort(events.begin(),events.end()) ; 
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1)); 
        return solve(0,events,k,dp) ;
    }
};

