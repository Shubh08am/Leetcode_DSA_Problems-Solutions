class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        //dp[i] = nums[i] + max(dp[i-k] , dp[i-k+1] , .... , dp[i-1]) 
        //Use sliding window maximum concept -> O(N)
        //ith position contribution till i+kth pos after that remove it
        //now, if we take any pos from i to i+k i.e i+x --> it goes to i+x+k i.e we take max contribution from i+xth to i+x+k-1th pos 

        int n = nums.size(),sum=INT_MIN;
        vector<int>dp(n,0);
        deque<int>dq;
        //dq in descending order 
        for(int i=0;i<n;i++){
            while(!dq.empty() && i-dq.front()>k){
                 dq.pop_front();
            }
            dp[i]=nums[i];
            if(!dq.empty()) dp[i]+=dp[dq.front()];
            sum=max(sum,dp[i]);
            while(!dq.empty() && dp[dq.back()]<dp[i]){
                dq.pop_back();
            }
            if(dp[i]>0)dq.push_back(i);
        }
    return sum;
    }
};
