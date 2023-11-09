class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long cnt=0,good=0; 
        unordered_map<int,int>freq;
        int i=0,j=0,n=nums.size();
        while(j<n){
            freq[nums[j]]++;
            cnt+=freq[nums[j]]-1;
            while(cnt>=k){
                good+=n-j;
                if(!--freq[nums[i]]) freq.erase(nums[i]);
                cnt-=freq[nums[i]];
                i++;
            }
        j++;
        }
    return good;
    }
};
