#define ll long long
class Solution {
public:
 
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
         ll pre[n + 1], suff[n + 1];
       ll ans=0, p = 1;
 
     for (int i = 0; i < k; i++){
        p<<=1;
     }
 
     pre[0] = 0; suff[n] = 0;
        
    for (int i = 0; i < n; i++){
        pre[i + 1] = pre[i] | nums[i];
    }
 
     
    for (int i = n - 1; i >= 0; i--){
        suff[i] = suff[i + 1] | nums[i];
 }
     for (int i = 0; i < n; i++){
        ans = max(ans, pre[i] | (nums[i] * p) | suff[i + 1]);
     }
 
    return ans;
    }
};
