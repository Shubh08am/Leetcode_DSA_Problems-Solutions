#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size() , m = nums2.size() ; 
        ll s1 = accumulate(nums1.begin(),nums1.end(),0ll);
        ll s2 = accumulate(nums2.begin(),nums2.end(),0ll);
        
         ll a = count(nums1.begin(),nums1.end(),0);
        ll b = count(nums2.begin(),nums2.end(),0);
        
        ll op1 = s1+a , op2 = s2+b ; 
        ll ans = op1>=op2?op1:op2;
        
        if(s1==s2 && a==0 && b==0) return s1; 
        if(a==0){
            if(op2>s1) return -1;
        }
        if(b==0){
            if(op1>s2) return -1;
        }
return ans;
    }
};
