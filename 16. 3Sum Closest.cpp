class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size() ,  left , right ;
        int sum=0 , dist_Btw_Sum= 1e5 , ans = 0;

sort(nums.begin(),nums.end()) ; 

        for(int i=0;i<n;i++){
        left = i+1;   right=n-1 ;

               while(left < right){
                   sum = nums[i] +  nums[left]  + nums[right] ;
                  
                   if( abs(sum-target) < dist_Btw_Sum) {
                         dist_Btw_Sum = abs(sum-target) ;
                         //candidate of answer 
                         ans = sum;
                         
                    }

                   if(sum==target) {
                       return sum;
                   }

                   else if(sum>target){
                             right--;
                   }
                   
                    else if(sum<target){
                            left++;
                   }
                   
               }
        }
        return ans;
    }
};




