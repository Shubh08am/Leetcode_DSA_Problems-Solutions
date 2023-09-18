class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int setBit =0 ; 
            for(int j=31;j>=0;j--) setBit+=((i>>j)&1) ;
            if(setBit==k) sum+=nums[i];
        }
        return sum;
    }
};
