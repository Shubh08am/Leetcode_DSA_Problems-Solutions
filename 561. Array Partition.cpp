class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        multiset<int>ms(nums.begin(),nums.end());
        int ans=0;
        auto it = ms.begin();
        while(it!=ms.end()){
            ans+=*(it);
            it++;
            it++;
        }
    return ans;
    }
};
