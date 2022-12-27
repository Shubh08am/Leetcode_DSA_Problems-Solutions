class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
   int n = nums.size();
        vector<int> res,l(n),r(n);    
        l[0] = 1; r[n - 1] = 1;

        for(int i = 1; i < n; i++){
            l[i] = l[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            r[j] = r[j + 1] * nums[j + 1];
        }
        
        for (int k = 0; k < n; k++) {
            int value = l[k] * r[k];
            res.push_back(value);
        }
        
        return res;       
    }
};
