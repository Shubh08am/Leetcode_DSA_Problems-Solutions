class Solution {
public: 
    int minimumSum(vector<int>& nums) {
         int n = nums.size(),c=0; 
        long long mn=1e18;
        vector<int> left_min(n) , right_max(n);
        left_min[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            left_min[i] = min(left_min[i - 1], nums[i]);
        }
        
        right_max[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            right_max[i] = min(right_max[i + 1], nums[i]);
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(left_min[i - 1] < nums[i] && nums[i] > right_max[i + 1])
            {
                c++;
                long long v = nums[i]+left_min[i-1]+right_max[i+1] ;
                mn= (mn>=v?v:mn);
             }
        }
        return c==0?-1: mn;
    }
};
