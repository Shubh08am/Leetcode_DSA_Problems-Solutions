class Solution {
public:
    int dp[100001][3] ; 
    //T.C ->  n*2*logn
    int bs(int value,int low,vector<vector<int>>& events){
        int high=events.size()-1 , ans = events.size();
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(events[mid][0]>value){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
     return ans; //return low;
    }
    int solve(int ind,int k,vector<vector<int>>& events) {
        if(ind==events.size() || k==0) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int notTake = solve(ind+1,k,events);
        //int nextPos = bs(events[ind][1],ind,events) ; 
        vector<int> search = {events[ind][1] , INT_MAX , INT_MAX};
        int nextPos = upper_bound(events.begin(),events.end(),search) - events.begin();
        int take=events[ind][2]+solve(nextPos,k-1,events);
        return dp[ind][k]=max(take,notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end()) ; 
        memset(dp,-1,sizeof(dp));
        return solve(0,2,events) ;
    }
};
