#define ll long long
class Solution {
public:
    
    bool checkPrime(ll n){
if(n<=1)  return false;
for(ll i = 2;  i<=sqrt(n) ; i++){
        if(n%i==0) return false;
    }
return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
         ll n = nums.size() , m = nums[0].size() , c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || j==n-i-1){
                    if(checkPrime(nums[i][j])) {
                        c=max((int)c,nums[i][j]);
                    }
                }
            }
        }
      return c;
    }
};
