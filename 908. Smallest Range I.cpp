class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()) ; 
        int ans=0;
        int n = nums.size() ; 
        nums[0]+=k;
        nums[n-1]-=k; 
        ans = nums[n-1]-nums[0] ; 
        return ans<0?0:ans;
    }
};
