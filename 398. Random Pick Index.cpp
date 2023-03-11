class Solution {
public: 
    map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        srand(time(0));
    }
    
    int pick(int target) { 
        auto it = mp[target] ; 
        int n = it.size() ; 
        int value = rand()%n;
        return it[value];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
