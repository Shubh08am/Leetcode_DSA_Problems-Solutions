class Solution {
    int mod = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subArray ;
            int sum=0;
        
        for(int i=0;i<n-1;i++){
               sum=0;
               for(int j=i+1 ; j<n;j++){
                   sum+= nums[i]+nums[j];
            subArray.push_back(sum);           
            sum-=nums[i];
               }
        }
        
         for(int i=0;i<n;i++){
            subArray.push_back(nums[i]);
         }
        sort(subArray.begin(),subArray.end()) ; 
       
      /*  for(int i=0;i<subArray.size();i++){
            cout<<subArray[i]<<" ";
         }
        cout<<"\n";
        */
        int res = accumulate(subArray.begin()+left-1,subArray.begin()+right,0LL) % mod ;
        
        return res;
    }
};
