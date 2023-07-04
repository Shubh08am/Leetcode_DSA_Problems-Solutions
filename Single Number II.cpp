class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //bits-manipulation 
        int num=0 , n = nums.size() ; 
        for(int i=0;i<32;i++){
            int setBit = 0 ;
            for(int j=0;j<n;j++){
                 if((nums[j]&(1<<i))) setBit++;
            }
           // cout<<setBit<<"\n";
            //group of 3 i.e divisible by 3 
            if(setBit%3!=0) num = num ^ (1<<i) ;
        }
    return num;
    }
};
