class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       //sliding window approach 
       //increase the window till we have both min and max element in it 
       int n = nums.size() , i=0 , j=0 , mn = -1 , mx= -1 , len=0; 
       long long int ans = 0 ; 

     while(j<n){ 
     //remove calculation for i 
    //when no mink and maxK in window - that window is not considered
    if(nums[j]<minK || nums[j]>maxK ){
      //reset position of minK and maxK to be -1 
      mn = -1 ; 
      mx = -1 ; 
      i=j+1;
    }
    //store position of minK and maxK 
    if(nums[j]==minK){
        mn = j ; 
    }
     if(nums[j]==maxK){
        mx = j ; 
    } 
    //take left-most one
    len = min(mn,mx) ; 
    //if len-i+1 < 0 don't take it 
    ans += max(0 , len-i+1) ;
    j++;
     }
       return ans;
    }
};
