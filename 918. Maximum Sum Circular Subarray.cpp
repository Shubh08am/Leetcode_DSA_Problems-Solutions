class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
 //use kadane algo as -ve no. sliding window failed 
     //corner case :- when max sum is splitted than kadane doesn't work there 
     //therefore use Total sum - min_sum 
     //when max sum is not splitted than kadane works fine 
    int maxSubarraySum=INT_MIN , totalSum=0  , minSubArraySum=INT_MAX  , currMaxSubarraySum=0, currMinSubArraySum=0;
        
    for(int i=0;i<nums.size();i++) {
        totalSum+=nums[i];

        currMaxSubarraySum+=nums[i];
        currMaxSubarraySum=max(currMaxSubarraySum ,nums[i]);
        maxSubarraySum=max(maxSubarraySum ,currMaxSubarraySum);
            
        //removing minSubArraySum from totalSum edge case
        currMinSubArraySum+=nums[i];
        currMinSubArraySum=min(currMinSubArraySum,nums[i]);
        minSubArraySum=min(minSubArraySum ,currMinSubArraySum);

       // cout<<maxSubarraySum<<" "<<minSubArraySum<<"\n";
        }
        
        //see for maxSum when maximum sum is obtained after rotation  
        int maxSubarraySumAfterRotation = totalSum-minSubArraySum;

       // cout<<maxSubarraySumAfterRotation<<"\n";
       if(maxSubarraySum<0) return maxSubarraySum ;

        return max(maxSubarraySum,maxSubarraySumAfterRotation);        
    }
};
