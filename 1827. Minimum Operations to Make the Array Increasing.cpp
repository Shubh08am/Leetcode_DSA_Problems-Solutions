class Solution {
public:
    int minOperations(vector<int>& nums) {
        //greedy 
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i+1<n && nums[i+1]<=nums[i]){
                int curr = abs(nums[i+1]-nums[i])+1 ;
                ans+=curr;
                nums[i+1]+= curr;
              //  cout<<i+1<<" "<<nums[i+1]<<"\n";
            }
        }
        return ans;
    }
};
