class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 ; 
        int e = nums.size()-1;
        int mid , ans; 
        
        while(s<=e){
        mid = s+(e-s)/2 ;
            
         if(nums[mid]==target){
             ans= mid ;
             return ans;}
    
       else if(nums[mid]>target){
            ans = mid ;
            e=mid-1;
            
           
     
            }
        
            else{
                ans=mid+1;
                s=mid+1;
                }}
        return ans;

    }
};
