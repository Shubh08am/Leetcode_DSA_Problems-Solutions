class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n=nums.size();
        long long ans=1e18;
        vector<int> mincost=nums;
        
        
        for(int i=0;i<n;i++){
            long long sum = 1ll*x*i; //from rotation cost
            for(int j=0;j<n;j++){
                mincost[j]=min(mincost[j],nums[(i+j)%n]);
                //take min cost
                sum+=mincost[j];
            }
            
            ans=min(ans,sum);//add in result 
        }
        
        return ans;
    }
};
