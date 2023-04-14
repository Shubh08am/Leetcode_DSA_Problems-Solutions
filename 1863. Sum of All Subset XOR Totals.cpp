class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(auto&i:nums){
            res= (res|i);
        } 
        while(n>1) {res<<=1; n--;}
        return res; 
        //return res * pow(2, --n); //or use this
    }
};
