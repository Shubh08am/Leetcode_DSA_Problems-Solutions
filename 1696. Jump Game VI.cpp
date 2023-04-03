class Solution {
public:   
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1);
        multiset<int> s;
        dp[n-1]=nums[n-1];
        s.insert(dp[n-1]);
        for(int i=n-2;i>=0;i--){
            int tmp=*(s.rbegin()); 
           // cout<<i<<" "<<tmp<<"->\n";
            dp[i]=tmp+nums[i];
         //  cout<<i<<" "<<tmp<<" "<<dp[i]<<"\n"; 
             s.insert(dp[i]);
            if(i+k<n)
            s.erase(s.find(dp[i+k]));
        } 
    //    for(auto&it:s) cout<<it<<" ";
      //  cout<<"\n";
      //   for(auto&it:dp) cout<<it<<" ";
       return dp[0];
    }
};
