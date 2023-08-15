class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0 ; 
        for(auto it : nums) xorr^=it ; 

        //find rightmost set bit 
        long setBit = xorr&~(xorr-1) ; 
        long setBitMethod2 = xorr&(-xorr) ; 

        //when bit = 1 -> any one number bit 1 
        //use this logic and group both numbers when bit set and unset
        int xorr1 = 0 , xorr2 = 0 ;
        for(auto it : nums){
            if(it&setBitMethod2) xorr1^=it; 
            else xorr2^=it;
        }
        return {xorr1,xorr2};
    }
};
