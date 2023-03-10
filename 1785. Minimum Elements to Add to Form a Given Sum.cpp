class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum = accumulate(nums.begin(),nums.end(),0LL);
        long long int toAdd = abs(goal-sum);
        long long int eleReq = ceil(toAdd*1.0/limit);
        return eleReq;
    }
};
