class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window -> variable sized window 
        int i=0,j=0;
        int sum=0 , minWindow=INT_MAX;
        while(j<nums.size()) {
             sum+=nums[j] ; 
            //again keep checking after removing calculation for i
            while(sum>=target){
                    minWindow = min(minWindow,j-i+1);
                    sum-=nums[i]; 
                    i++;
            }
        j++;
        }
    return minWindow==INT_MAX?0:minWindow;
    }
};
