class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        int n = nums.size(); 
        int i=0,j=n-1,mini=0;
        while(i<j){
            mini=max(mini,nums[i++]+nums[j--]);
        }
        return mini;
    }
};
