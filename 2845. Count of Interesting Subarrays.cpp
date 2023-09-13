#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        ll n = nums.size() , ans=0 , preSum=0 , b=0; 
        map<int,int>mp;
        bool flg=0;
        vector<ll>pre(n) ; 
        pre[0] = nums[0]%mod;
        for(int i=1;i<n;i++){
            pre[i] = (pre[i-1] + nums[i])%mod;
        }
        mp[0]=1;
        for(int i=0;i<n;i++){
            ll val = ((nums[i]%mod)-k==0);
            
            preSum = (preSum+val)%mod;
           // cout<<preSum<<"\n";
            b = (preSum+mod-k)%mod;
         //   cout << preSum << " "<< b << "\n" ;
            if(mp.count(b)) {
             //   cout<<b<<" ";
                ans+=mp[b];
            }
            mp[preSum]++;
            // if(k!=0) mp[preSum%mod]++;
          }
       return ans;
    }
};
