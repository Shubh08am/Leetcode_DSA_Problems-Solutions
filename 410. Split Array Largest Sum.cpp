class Solution {
public:
    bool isPossible(long long &mid,vector<int>& nums, int k) {
        int split = 1 ;
        long long sum = 0; 
        for(auto & val : nums){
            if(sum + val <= mid) {
                sum+=val;
            }
            else{
                split++;
                sum=val;
            }
        }
    return split<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        //like Book Allocation 
        int n = nums.size() , low = *max_element(nums.begin(),nums.end()) ;
        long long high = accumulate(nums.begin(),nums.end(),0LL) ; 
        while(low<=high){
            long long mid = low + (high - low) / 2 ; 
            if(isPossible(mid,nums,k)) high = mid-1; 
            else low = mid+1;
           // cout << low << " "<<high<<" "<<mid<<"\n";
        }
    return low;
    }
};
