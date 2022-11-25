class Solution {
public:
    int d(int n)
{
    string s;
      while(n){
      if(n & 1)  s+='1';
      else s+='0';
      n>>=1;  
    }   
        reverse(s.begin(),s.end()) ;
        int cnt = count(s.begin(),s.end(),'1');
        if(cnt==s.size()) return 1;
        
      return 0;
}
    
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
       long long int ans=0 , res=0;
        
        // consecutie no. with set bit all is answer or max no.
        long long int mx = *max_element(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(nums[i]==mx) ans++;
            else if(nums[i]!=mx){
                res=max(res,ans) ; ans=0;
            }
        }
        //if not reached elese
        res=max(res,ans) ;
        return res;
    }
};
