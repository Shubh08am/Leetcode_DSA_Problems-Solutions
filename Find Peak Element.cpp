class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 1st l.s approach
     /*   if(nums.size()==2){ 
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
        */
        
        // 2nd l.s approach 
        /*
          for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.size() - 1; 
        */
        //3rd b.s approach 
        int s = 0; 
        int e = nums.size()-1 ;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]<nums[mid+1])
            { s=mid+1;    
            }
            else if (nums[mid]>nums[mid+1])
            { e = mid;}
            
             mid = s + (e-s)/2;
        }
        return s;
    }
};
