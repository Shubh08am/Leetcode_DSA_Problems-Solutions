class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0 ; 
        for(auto & it : nums) g = __gcd(g,it) ;
        return g==1;
    }
};
