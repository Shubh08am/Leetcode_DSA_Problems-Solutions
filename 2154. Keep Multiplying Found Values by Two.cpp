class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       unordered_set<int>s(nums.begin(),nums.end());
        while(1){
            if(!s.count(original)) return  original;
            original<<=1;
        }
    return 0;
    }
};
