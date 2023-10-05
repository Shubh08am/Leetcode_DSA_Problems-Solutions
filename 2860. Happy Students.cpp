class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        int ways=0,n=nums.size(); 
        for(int i=0;i<n-1;i++){
            if(nums[i]<=i && nums[i+1]>i+1) ways++;
        }
        if(nums[n-1]<n) ways++;
        if(nums[0]>0) ways++;
        return ways;
    }
};
