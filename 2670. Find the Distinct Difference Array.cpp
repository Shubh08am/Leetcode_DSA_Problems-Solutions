class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            set<int>s(nums.begin(),nums.begin()+i+1);
            set<int>ss(nums.begin()+i+1,nums.end());
            ans[i] = s.size()-ss.size();
        }
         return ans;
    }
};
