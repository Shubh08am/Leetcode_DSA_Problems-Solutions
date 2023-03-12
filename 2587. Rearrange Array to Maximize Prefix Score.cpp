#define ll long long
class Solution {
public:
    int maxScore(vector<int>& nums) {
      
        ll c=0;
        int n = nums.size() ; 
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
          vector<long long int>a(n); 
        a[0] = nums[0] ; 
        for(int i=1;i<n;i++){
               ll val = a[i-1]+nums[i] ; 
            a[i] = val ; 
          }
        
        for(int i=0;i<n;i++){
            if(a[i]>0) c++;
        }
         return c; 
    }
};
