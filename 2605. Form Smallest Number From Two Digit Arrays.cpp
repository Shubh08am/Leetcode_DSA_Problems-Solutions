class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m,mp;
        for(auto&it:nums1) m[it]++;
        for(auto&it:nums2) mp[it]++;
        sort(nums1.begin(),nums1.end()) ; 
         sort(nums2.begin(),nums2.end()) ; 
        for(int i=0;i<nums1.size();i++){
            if(m[nums1[i]] && mp[nums1[i]]) return nums1[i] ;
        }
        int ans = min(nums1[0],nums2[0])*10+max(nums1[0],nums2[0]);
        return ans;
    }
};
