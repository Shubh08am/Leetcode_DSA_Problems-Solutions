class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp ; 
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(auto it : nums[i]){
                if(i==0) mp[it]=i+1;
                else {
                    if(mp[it]==i){
                        mp[it]=i+1;
                    }
                }
            }
        }
        for(auto it : mp){
            if(it.second==nums.size()) ans.push_back(it.first);
        }
    return ans;
    }
};
