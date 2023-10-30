class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size() ;  long long ans=0;
        for(int i=0;i<n;i++){
            set<int>a;
            for(int j=i;j<n;j++){
                 a.insert(nums[j]);
                   int v=a.size();
            ans+=(1ll*v*v) ;
            }
        }
        return ans;
    }
};
