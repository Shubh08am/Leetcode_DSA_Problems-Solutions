class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int cnt = 0 , sum = 0 , n = nums.size() , i=0, j=0; 
         while(j<n){
            sum+=nums[j]; 
            if(sum>k){
                //remove calculation for i 
                while(sum>k){
                    sum-=nums[i++];
                }
            }
            if(sum<=k) cnt+=(j-i+1);
            j++;
        }
    return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); 
        //replace even by 0 and odd by 1 
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]&1)?1:0 ; 
        }
        //calculate the subarrays with sum = k.
        //finding the subarrays with sum <= k and finding subarrays with sum <= k - 1 and subtrack later from the previous one.
      // return solve(nums,k) - solve(nums,k-1) ; 

      //use sub-array with sum k 
      unordered_map<int,int>mp; 
      int ans=0,prefix_Sum=0;
      mp[0]=1;
      for(int i=0;i<n;i++){
          prefix_Sum+=nums[i];
          ans+=mp[prefix_Sum-k];
          mp[prefix_Sum]++;
      }
    return ans;
    }
};
