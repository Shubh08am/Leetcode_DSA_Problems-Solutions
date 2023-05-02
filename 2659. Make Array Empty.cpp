#define ll long long
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        ll ans=1,n=nums.size();
        vector<pair<ll,ll>>vp(n);
        for(int i=0;i<n;i++){
            vp[i]={nums[i],i};
        }
        sort(vp.begin(),vp.end());
        ll count=n;
        
        for(int i=0;i<n-1;i++){
            if(vp[i].second >= vp[i+1].second) {
                count+=n-ans;
            }
                ans++;
        }
        return count;
    }
};
