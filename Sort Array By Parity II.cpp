class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        //2 ptr --> Brute Force using additional space
      /*   int odd = 1  ; 
        int even = 0 ; 
        vector<int>ans(nums.size());
        for(int i=0 ; i<nums.size();i++) {
            if(nums[i]&1) {
                ans[odd] = nums[i];
                odd+=2;
            }
           else if(!(nums[i]&1)) {
                ans[even] = nums[i];
                even+=2;
            }     
        }
        return ans;    
        */
        
        // optimized Approach 
        int odd = 1  ; 
        int even = 0 ; 
        int n = nums.size();
        while(odd<n and even<n){
            // odd element at odd pos 
            if(nums[odd]&1) { odd+=2;}
        // even element at even pos 
             else if(!(nums[even]&1)) {even+=2;    }
            // odd element at even position and even element at odd position 
            else if(!(nums[odd]&1) || nums[even]&1){
                swap(nums[odd],nums[even]);
            }

        }
        return nums;
    }
};
