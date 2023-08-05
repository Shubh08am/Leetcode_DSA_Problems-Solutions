class Solution {
public:
    bool isPossible(int mid,vector<long long>& pre) {
        int n = pre.size()  , cnt=0; 
        for(int i=n-1;i>=0;i--){
            long long val = (1ll*(mid-cnt))*(1ll*(mid-cnt)+1)/2 ;
            //possible to create a group of mid number
            if(val<=pre[i]) cnt++; 

            if(cnt>=mid) return 1;

            //mid number of groups not possible
            if(val>pre[i]){
                return 0;
            } 
            
        }
    return 0;
    }
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(),usageLimits.end()) ; 
        int n = usageLimits.size() , low = 1 , high = n ,ans=1;
        vector<long long>pre ; 
        for(int i=0;i<n;i++) pre.push_back(usageLimits[i]);
        for(int i=1;i<n;i++) pre[i]+=pre[i-1]; 
        while(low<=high){
            int mid = low + (high-low)/2 ; 
            if(isPossible(mid,pre)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
    return high;//return ans;
    }
};
