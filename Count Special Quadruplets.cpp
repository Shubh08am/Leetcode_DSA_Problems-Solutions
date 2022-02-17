class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt= 0;

    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int o=j+1;o<n-1;o++){
                for(int p=o+1;p<n;p++){
                    if((nums[i]+nums[j]+nums[o])==nums[p])
                        cnt++;
                }
            }
       }
    }
    return cnt ;  
    }
};
