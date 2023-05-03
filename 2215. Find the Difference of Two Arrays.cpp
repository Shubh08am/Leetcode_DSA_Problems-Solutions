class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
         vector<vector<int>>ans(2);
         unordered_set<int>freq(nums2.begin(),nums2.end()) ; 
         for(auto&val:nums1){
             if(!freq.count(val)) {ans[0].push_back(val);freq.insert(val);}
         }
          unordered_set<int>freq2(nums1.begin(),nums1.end()) ; 
         for(auto&val:nums2){
             if(!freq2.count(val)) {ans[1].push_back(val);freq2.insert(val);}
         }
         return ans;
    }
};
