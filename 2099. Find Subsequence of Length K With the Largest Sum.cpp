class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>v;
        vector<pair<int,int>>vp,rp;
        for(int i=0;i<nums.size();i++) vp.push_back({nums[i],i});
        sort(vp.rbegin(),vp.rend());
        for(int i=0;i<k;i++){
            rp.push_back({vp[i].second,vp[i].first});
        }
        sort(rp.begin(),rp.end());
        for(int i=0;i<k;i++) v.push_back(rp[i].second);
    return v;
    }
};
