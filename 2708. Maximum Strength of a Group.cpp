class Solution {
public:
       long long solve(int i,long long ans,vector<int>&nums,int product){
        int n=nums.size();    
        if(i==n) return product==0?INT_MIN:ans; 
        //take and notTake 
        long long notTake = solve(i+1,ans,nums,product) ; 
        long long take =   solve(i+1,ans*nums[i],nums,1);
       // cout<<i<<" "<<take<<" "<<notTake<<" "<<"\n";
        return max(take,notTake);
    }
    long long maxStrength(vector<int>& nums) {
        //greedy and dp both works 
        int n=nums.size();
        return solve(0,1,nums,0) ; 
     }
};
