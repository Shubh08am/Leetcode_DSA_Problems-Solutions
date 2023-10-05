#define ll long long
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        vector<ll>square; 
        int n = nums.size(); 
        ll ans=0;
        for(ll i=1;i*i<=n;i++) square.push_back(i*i);
        for(ll i=1;i<=n;i++){
            ll val=0;
            for(auto x : square){
                if(i*x>n) break;
                val+=nums[i*x-1];
               // cout<<i<<" "<<x<<" "<<val<<"\n";
            }
        ans=max(ans,val);
        }
    return ans;
    }
};
