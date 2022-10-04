class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     //kadane Algorithm
        int curr_sum = 0 ; 
        int max_sum = nums[0]; 
        
        for(auto&it:nums){
            
          curr_sum+=it; 
            if(curr_sum > max_sum){
                max_sum=curr_sum;
            }
           if(curr_sum < 0) { 
               curr_sum = 0 ; 
           } 
            
        } 

        return max_sum;
    }
};
