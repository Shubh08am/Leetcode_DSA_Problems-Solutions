class Solution {
public:
    vector<int> productExceptSelf2(vector<int>& nums) {
        // prefix - suffix 
        int n  = nums.size() ; 
        vector<int>preffix(n) , suffix(n) , ans(n); 
        preffix[0] = suffix[n-1] = 1 ; 
        //product of every element before i
        for(int i=1;i<n;i++){
            preffix[i] = preffix[i-1] * nums[i-1] ; 
        } 
        //product of every element after i
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1] ;
        }
        //preffix[i] * suffix[i] contains product of every element before i and every element after i but not the element at index i (and that is the reson why we excluded a[i] in our prefix and suffix product).
        for(int i=0;i<n;i++){
            ans[i] = preffix[i] * suffix[i] ; 
        } 
    return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        // no need of separate prefix - suffix directly store it in answer 
        //O(1) SC
        int n  = nums.size() ; 
        vector<int> ans(n,1); 
        int product = 1 ; 
        //prffix part
        for(int i=0;i<n;i++){
            ans[i] = ans[i]*product ; 
            product*=nums[i];
        }
        //suffix part
        product=1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i]*product;
            product*=nums[i];
        }
    return ans;
    }
};
