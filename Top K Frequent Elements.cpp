class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
 unordered_map<int,int>mp;

for(auto&it:nums) mp[it]++;

vector<pair<int,int>>vp;

for(auto&it:mp){	
	vp.push_back({it.second,it.first});
}

sort(vp.begin(),vp.end());
reverse(vp.begin(),vp.end());
vector<int>ans;
for(int i=0;i<k;i++){
ans.push_back(vp[i].second);	
}

return ans;       
    }
};
