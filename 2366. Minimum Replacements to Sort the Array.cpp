class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0 ;
        int n = nums.size() , initial = nums[n-1];
//start from back and when condition violated do partition of number such that it is smaller than next one and maximum at the same time 
        
        for(int i=n-2;i>=0;--i){
            if(nums[i]<=initial){ 
                initial=nums[i];
            }
                int totalSplit = (nums[i]+initial-1)/initial ; 
                ans+=totalSplit-1;
                //update initial now 
                initial = nums[i] / totalSplit ;
            
        }
        return ans;
    }
};
