class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size() ; 
    for (int i = 0; i < n; i++) s.insert(nums[i]);
 
    int m = s.size(),v=0;
 
    for (int i = 0; i < n; i++) {
        unordered_set<int> t;
        for (int j = i; j < n; j++) {
            t.insert(nums[j]);
            if (t.size() == m)
                v++;
        }
    }
 
    return v;
    }
};
