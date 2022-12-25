class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&it:nums){
            mp[it]++;
        }
        for(int i=1000;i>=1;--i){
            if(mp[i]>0 and mp[-1*i]>0) return i;
        }
        return -1;
    }
};
