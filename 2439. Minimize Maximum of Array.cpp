#define ll long long
class Solution {
public:
    bool isPossible(ll mid, vector<int>& nums){
        vector<ll>arr(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]>mid){
                return false;
            }
            arr[i+1] = arr[i+1] - (mid-arr[i]);
        }
        //till last index possible 
        return arr[n-1]<=mid;
    }
    //Approach-2 Greedy
    int prefixSum(vector<int>& nums){
        int n = nums.size() , ans=0;
        vector<ll>pre(n);
        pre[0]=nums[0];
        for(int i=0;i<n-1;i++){
            pre[i+1]=pre[i]+nums[i+1];
        } 
      //  for(int i=0;i<n;i++){
      //      cout<<pre[i]<<" ";
      //  } 
        for(int i=0;i<n;i++){
           int currRes = ceil((pre[i]*1.0)/(i+1) ); 
           //int currRes = (pre[i]+i)/(i+1) ; //or use this
           ans=max(ans,currRes);
        } 
        return ans;
    }
    int minimizeArrayValue(vector<int>& nums) { 
        //Approach-1 Binary Search
        //binary search -> o(nlogn)
        /*
        int start=0,end=1e9;
        while(start<end){
            ll mid = start+(end-start)/2;

            if(isPossible(mid,nums)){
                end=mid;
            }
           else{
               start=mid+1;
           }
        }
        return end;
        */
        return prefixSum(nums);
    }
};
