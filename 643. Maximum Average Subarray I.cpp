class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN , curr = 0.0; 
        int i=0,j=0,n=nums.size() ; 
        while(j<n){
            curr+=nums[j];
            if(j-i+1==k){
                res = max(res,(double)curr/k);
                curr-=nums[i++];
            }
            j++;
        }
    return res;
    }
};
