class Solution {
public:
    int rob(vector<int>& nums) {
         /*
       2 1 1 2 
       take 2 than skip 1 , 1 again take 2 -->  answer -> 4
        */

        int evenPos_Sum=0 , oddPos_Sum=0 , max_sum=0; 
       
        for(int i=0;i<nums.size();i++){
            //if at even index position -> 0,2,4...
            if(!(i&1)){
          evenPos_Sum+=nums[i];
           evenPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
            //if at odd index position -> 1,3,5...
            if((i&1)){
          oddPos_Sum+=nums[i];
          oddPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
}
   
        max_sum = max(evenPos_Sum,oddPos_Sum);
        return max_sum;
    }
};
