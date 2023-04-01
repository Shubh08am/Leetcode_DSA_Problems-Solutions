class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
       vector<long long> pre;
        sort(nums.begin(),nums.end());
        long long sum=0 , n=nums.size();
        for(auto it:nums){
            sum+=it;
            pre.push_back(sum);
        }
        vector<long long> ans;
        for(auto &it:queries){
            int index=lower_bound(nums.begin(),nums.end(),it)-nums.begin();
            //before lower bound index increase operation and after that decrease operation 
           int lbVal = *lower_bound(nums.begin(),nums.end(),it) ;
      //   cout<<it<<" "<<index<<" "<<lbVal<<"\n" ;
            if(index==0){
                ans.push_back(pre[n-1]-(long long)it*(n));
            }
            else{
                long long operAfter = pre[n-1]-pre[index-1]-(long long)it*(n-index);
                long long operBefore = it*(long long)(index)-pre[index-1] ; 
                ans.push_back(operAfter+operBefore);
            }
        }
        return ans;
    }
};
