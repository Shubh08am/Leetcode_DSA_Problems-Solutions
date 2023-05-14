class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
/*       First, increase till a point and then decrease.
        Goes on increasing (Longest increasing subsequence) [LIS]
        Goes on decreasing (Longest decreasing subsequence) [LDS]
*/
      
	    int n=nums.size();
         // Length of lis can always be 1 include single elements only therefore initialized to 1 
         //LIS FROM FRONT
	     vector<int>dp(n,1);
         for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]>nums[prev_ind] && 1+dp[prev_ind] > dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                }
            }
         }
         
          //LIS FROM BACK
          vector<int>dp2(n,1);
          for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
                if(nums[ind]>nums[prev_ind] && 1+dp2[prev_ind] > dp2[ind]){
                    dp2[ind]=1+dp2[prev_ind];
                }
            }
         }

      int Bitonic=1;
      /*  for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++) cout<<dp2[i]<<" ";
        */

        //HERE, BITONIC DEFINITON INCLUDE BOTH INCREASING && DECCREASING

        //EX:- [9,8,1,7,6,5,4,3,2,1] -> REMOVE [9,8] -> THAN 7>1 && 7>6>5>4>3>2>1 
         for(int i=0;i<n;i++){
          if(dp[i]!=1 && dp2[i]!=1)   Bitonic=max(Bitonic,dp[i]+dp2[i]-1);
        } 
        return n-Bitonic;
    }
};
