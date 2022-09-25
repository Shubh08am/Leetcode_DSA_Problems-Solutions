class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size()+nums2.size();
        vector<int>v;
        v=nums1;
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
         double ans = 1.0000;
        
        sort(v.begin(),v.end());
        if(sz&1){
             ans*=v[sz/2];
        }
        else{
           ans*=(v[sz/2]+v[sz/2-1])/2.0 ;
        }
        return ans;
    }
};
