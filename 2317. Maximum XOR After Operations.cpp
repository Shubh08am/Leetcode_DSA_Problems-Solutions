class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        //at Max answer can be 2^(n-1) where n is no. of bits in maximum element 
        //i.e all bit can be sit 
        //if any no. in the range 2^x to 2^y than some bit can be made set or unset using some x 
        //ex:-6 (2^2 - 2^3) using 4 -> 6&(6^4) ->6&2 -> 2 
        //take or of all will give best result as it tried to take set bit only from all number 
        int xorr=0;
        for(auto&x:nums) xorr|=x;
        return xorr;
    }
};
