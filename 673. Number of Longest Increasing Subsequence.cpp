class Solution {
public:
   //Time Complexity: O(N*N)+O(N) Space Complexity: O(2*N)
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),lis=1,no=0;
        vector<int>dp(n,1),cnt(n,1);

        for(int ind = 0 ; ind<n; ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind] > nums[prev_ind] && 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind]; 
                    cnt[ind]=cnt[prev_ind]; //inherit prev_ind cnt
                }
                else if(nums[ind] > nums[prev_ind] && 1+dp[prev_ind]==dp[ind]){
                    cnt[ind]+=cnt[prev_ind]; //when same dp value cnt increased 
                }
            }
            lis=max(lis,dp[ind]);
        }
        //all corresponding cnt with same lis is added in Number of Longest Increasing Subsequence
        for(int i=0;i<n;i++){
            no+=lis==dp[i]?cnt[i]:0;
        }
        return no;
    }
};
