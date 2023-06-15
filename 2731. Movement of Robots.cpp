const int mod = 1e9+7;
#define ll long long
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        ll n= s.size() , prefix_sum=0,curr_sum=0,m=nums.size();
 
        
         for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                nums[i]-= d;
            } 
             else if (s[i] == 'R') {
                nums[i]+= d;
            }
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < m; i++) {
            curr_sum+=(ll)(nums[i] * i*1LL) - prefix_sum;
            curr_sum%=mod;
            prefix_sum+=nums[i];
            prefix_sum%=mod;
        }
        curr_sum%=mod;
        return curr_sum;
    }
};
