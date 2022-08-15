class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     int cnt = 0 ; 
  
if(nums.size()==1){
    
    if(nums[0]==0) return 0;
    else return 1 ;
    }
   
 
       for(int i=0 ; i< nums.size();i++){
           sort(nums.begin(),nums.end());
        if(nums[i]!=0){
            int an = nums[i] ;
            cnt++;
            for(int i=0 ; i<nums.size();i++){ 
                if(nums[i]!=0){
           nums[i]-=an ; 
          } } 
            }
              }
          
    
        return cnt ;
    }
};
