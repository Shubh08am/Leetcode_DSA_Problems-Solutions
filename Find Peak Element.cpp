class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==2){ 
              if(nums[0]>nums[1])
                return 0;
            
            else
            return 1;
        }
       
         if(nums.size()==0){ 
                return 0;
         }
        else{ 
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i-1]>nums[i] && nums[nums.size()-1]<nums[nums.size()-2])
            { 
                return i-1;
            break;}
        
                
        }}
        return nums.size()-1;
    }
};
