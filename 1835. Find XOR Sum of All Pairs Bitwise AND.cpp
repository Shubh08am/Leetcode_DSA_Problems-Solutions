class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        //xor of arr1 & xor of arr2 will work
//(A&C) ^ (B&C) = (A^B) & (C)
/*
 arr1 = [1,2,3], arr2 = [6,5]
 (1&6)^(1&5)^(2&6)^(2&5)^(3&6)^(3&5)
 
 We can simplify it as:
 (1&(6^5))^(2&(6^5))^(3&(6^5))
 
 So finally we can write it as:
 (6^5)&(1^2^3)
 */
        int xorr1=0,xorr2=0;
        for(auto&val:arr1) xorr1^=val;
        for(auto&val:arr2) xorr2^=val;
        return xorr1&xorr2;
    }
};
