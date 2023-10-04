#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        ll sum = accumulate(nums.begin(),nums.end(),0ll); 
        ll val = 0,i=0,n=nums.size(),j=0,len=1e9;
        while(val<=target){
            val+=nums[i%n];
            nums.push_back(nums[i%n]) ; 
            i++;
        }
        i=0,n=nums.size(),sum=0 ; 
        while(j<n){
            sum+=nums[j]; 
             while(sum>target) sum-=nums[i++];
                if(sum==target) {
                 len=min(len,j-i+1);
                 sum-=nums[i];
                 i++;
             }
            j++;
        }
        return len==1e9?-1:len;
    }
};
