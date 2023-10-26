class Solution {
public:
    const int mod = 1e9+7; 
    int solve(int parent,vector<int>& nums,unordered_map<int,int>&dp,unordered_map<int,int>&factors){
        if(dp.find(parent)!=dp.end()) return dp[parent] ; 
        int cnt=1; 
        for(int i=0;i<nums.size();i++){
            int child1 = nums[i] ; 
            //child1 factor of parent 
            if(parent%child1==0){
                //make sure child2 is present now 
                int child2 = parent/child1 ; 
               if(factors[child2]==0) continue;
                cnt=(cnt+(1ll*solve(child1,nums,dp,factors)*solve(child2,nums,dp,factors))%mod)%mod;
            }
        }
      //  cout<<parent<<" "<<cnt<<"\n";
    return dp[parent]=cnt;
    }
    int numFactoredBinaryTrees(vector<int>& nums) {
        /*
           nums[i] ke saare factor agar present hain tho hii possible hain
           10 -> 1,2,5,10 
           if 2,5 present -> 10,2,5 || 10,5,2 
           if 1,2,5 present -> than also same as 2 child of nodes 

           recursion -> try all ways possible 
           parent , child1 , child2 

           if nums[i] is the parent 
           first find one factor of nums[i] which is child1 
           Now, child2 = nums[i]/child1  
           both child1 and child2 should be present in nums
           ans is cnt = cnt + solve(nums[i],child1,child2) + solve(nums[i],child2,child1);
        */
        unordered_map<int,int>dp;
        unordered_map<int,int>factors;
        for(int i=0;i<nums.size();i++) factors[nums[i]]++; 
        int ans = 0 ; 
        for(int i=0;i<nums.size();i++){
            int parent = nums[i] ; 
            ans = (ans+solve(parent,nums,dp,factors))%mod;
        }
        return ans ;
    }
};
