class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int n=nums.size(),i=0,j=0,cnt=0,sum=0;
        if(goal<0) return 0;
        while(j<n){
            sum+=nums[j];
            if(sum>goal){
                while(sum>goal){
                    sum-=nums[i++];
                }
            }
            cnt+=j-i+1;
            j++;
        }
    return cnt;
    }
     int numSubarraysWithSum(vector<int>& nums, int goal) {
        //atmost(goal sum) - atmost(goal-1 sum) 
        //or subarray with sum k 
        unordered_map<int,int>mp;
        mp[0]=1;
        int n = nums.size() , ans = 0 ,prefix_Sum=0; 
        for(int i=0;i<n;i++){
            prefix_Sum+=nums[i] ; 
            ans+=mp[prefix_Sum-goal];
            mp[prefix_Sum]++;
        }
    //return solve(nums,goal) - solve(nums,goal-1) ; // APPROACH-1 SLIDING WINDOW
    return ans; // APPROACH-2 subarray with sum k 
    }
};
