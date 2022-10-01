class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto&it:nums) mp[it]++;
        for(auto&it:nums){
            if(mp[it]==1 and mp[it-1]==0 and mp[it+1]==0) ans.push_back(it);
        }
        return ans;
    }
};
