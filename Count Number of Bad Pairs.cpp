class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    long long int n=nums.size();
        unordered_map< long long int, long long int>mp;
        
 long long int ans = 0;

for(int i=0 ; i<n ; i++){
     ans+=i-mp[nums[i]-i]++;   
    }
return ans;     
    }
};
