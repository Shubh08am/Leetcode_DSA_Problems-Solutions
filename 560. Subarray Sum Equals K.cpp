class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //hashing no sliding windows as -ve elements are present 
        //prefix sum 
        /*
       [3 4 7 2 -3 1 4 2]
       prefix sum - 3 7 14 16 13 14 18 20 
       if in prefix sum any value == k take it 
       if in prefix sum (ith value of prefix sum - k ) present take it 
        */ 
        int cnt=0 , n = nums.size() ;
        unordered_map<int,int>freq;
        freq[0]=1;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            cnt+=freq[nums[i]-k];
            freq[nums[i]]++;
        }
    return cnt;
    }
};
