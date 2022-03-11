class Solution {
public:
    int pivotIndex(vector<int>& nums) {
int sum = 0, leftsum = 0;
       sum = accumulate(nums.begin(),nums.end(),0);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            else    leftsum += nums[i];
        }
        return -1;    
    }
};
