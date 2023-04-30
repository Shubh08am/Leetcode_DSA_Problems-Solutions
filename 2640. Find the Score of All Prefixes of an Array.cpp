class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>v;
        long long int n=nums.size() , sum=0;
        priority_queue<long long>pq;
        for(int i=0;i<n;i++){
             pq.push(nums[i]);
            long long maxi = pq.top();
              sum += nums[i]+maxi;
            v.push_back(sum);
        }
         return v;
    }
};
