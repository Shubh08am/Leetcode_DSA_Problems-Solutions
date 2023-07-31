class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1 , n = nums.size() ; 
        for(int i=n-2;i>=0;i--){
             //find break point
             if(nums[i]<nums[i+1]){
                 ind=i;
                 break;
             }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            //Replace nums[ind] with just greater element 
            for(int i=n-1;i>=ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            //everyone after ind position needs to be sorted 
            reverse(nums.begin()+ind+1,nums.end()) ;
        }
    }
};
