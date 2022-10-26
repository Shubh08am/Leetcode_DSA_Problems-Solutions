class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
    int n=nums.size(); 
    int ans = nums[0]; 
    int sum = 0; 
     
     for(int i=1;i<n;++i){
         
      if(nums[i-1]<nums[i]) {
       ans+=nums[i];   
          }
     else{
      sum=max(ans,sum);
        ans=nums[i];
         
         }
         }
  sum = max(ans,sum);
       return sum;
    }
};
