class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
        //   cout<<low<<" "<<mid<<" "<<high<<"\n";
           if(nums[mid]==target) return true; 
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]) {
                low++;
                high--;
             }
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low]&&target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
                if(target>=nums[mid]&&target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
    return false;
    }
};
