class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int ind = max_element(nums.begin(),nums.end())-nums.begin();
        for(auto&it:nums){
            if(it!=mx && it>0){
                if(mx/it<2) return -1;
            }
        }
    return ind;
    }
};
