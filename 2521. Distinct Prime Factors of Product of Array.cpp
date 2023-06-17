class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        map<int,vector<int>>factor;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    factor[j].push_back(i) ; 
                    while(nums[i]%j==0) nums[i]/=j;
                }
            }
                if(nums[i]>1) factor[nums[i]].push_back(i);
        }
    return factor.size();
    }
};
