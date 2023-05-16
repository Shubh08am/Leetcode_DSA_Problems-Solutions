#define ll long long
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size() , m=nums[0].size()  ; 
         ll a=0; 
        for(auto &v : nums) sort(v.begin(),v.end()) ; 
          for(int i=0;i<m;i++){
            ll c=0;
            for(int j=0;j<n;j++){
                if(nums[j][i]>c){
                    c=nums[j][i] ; 
                }
            }
            cout<<c<< " ";
            a+=c;
        }
        return a;
    }
};
