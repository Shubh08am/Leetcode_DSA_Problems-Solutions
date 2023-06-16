class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        int n= nums.size() ; 
        if(n<3) return -1;
        return nums[1] ; 
    }
};
