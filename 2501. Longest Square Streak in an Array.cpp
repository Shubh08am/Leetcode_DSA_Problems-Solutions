class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       long long int res=0 , cnt=0;
        map<long long int,long long int>mp;
        
        for(int i=0;i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            long long int ans=1 ;
              long long int curr = (nums[i]*1LL)*(nums[i]*1LL)*1LL;
            //search till true for max value
            while(mp[curr]>0){ 
                ans+=1;cnt+=1;
                curr = curr*curr*1LL;
            }
            //find max 
            res=max(res,ans);
        }
        
        if(cnt==0) return -1;
        return  res;
    }
};
