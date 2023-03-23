#define ll long long
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        ll c=0 , n=nums.size(); 
        unordered_map<ll,ll>mp;
        for(auto it : nums){
            mp[it]++;
        }
         for(auto it : mp){
          c=max(c,it.second);
        }
          return n-c ;
    }
};
