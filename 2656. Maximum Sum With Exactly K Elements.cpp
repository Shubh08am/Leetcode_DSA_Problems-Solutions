class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
       long s=0;
        sort(nums.begin(),nums.end()) ; 
        long i = nums.back(); 
         while(k>1){
            s+=i;
            i++;
            k-=1;
        }
        return s+i;
    }
};
