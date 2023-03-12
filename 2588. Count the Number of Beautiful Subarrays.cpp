#define ll long long
class Solution {
public:
     
    long long beautifulSubarrays(vector<int>& nums) {
        ll c=0 , n = nums.size() , xorr=0; 
        unordered_map <ll, ll>mp;
     for (int i = 0; i < n; i++){ 
           xorr ^=nums[i] ;
         mp[xorr]++;
     }
        for(auto it : mp) {
            if(it.first==0) c+=it.second;
            c+=(it.second)*(it.second-1)/2;
        }
          return c ; 
    }
};
