class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m;
        sort(nums.begin() , nums.end());
        for(int i=1 ; i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]) 
                m= nums[i];
        }
        return m;
    }
};
