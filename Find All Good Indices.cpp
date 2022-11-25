class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        //prefix and suffix
        int n = nums.size();
        vector<int>pre(n),suf(n) , ans;
        pre[n-1]=1;
        suf[0]=1; 
        //see prefix
        for(int i=n-2;i>=0;i--){
            //compare
            if(nums[i+1]>=nums[i]) pre[i]=pre[i+1]+1;
            else pre[i]=1;
        }
       
             //see suffix
     for(int i=1;i<n;i++){
            //compare
            if(nums[i-1]>=nums[i]) suf[i]=suf[i-1]+1;
            else suf[i]=1;
        }
         for(int i=1;i<n-1;i++){
            //compare pre and suf
            if(pre[i+1]>=k and suf[i-1]>=k) ans.push_back(i);
        }
        return ans;
    }
};
