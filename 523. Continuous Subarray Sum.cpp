class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>sub;
    sub[0]=-1;
    int curr_sum =0;
     int n = nums.size () ;
    for (int i =0;i<n ;i++){
         curr_sum += nums[i];
         curr_sum=curr_sum%k;
        if (sub.find (curr_sum)!=sub.end()){
                if (sub[curr_sum]!=i-1){
                 return 1;
                }                
          }
                                                                                                                                                        else {
        sub[curr_sum]=i;
        }
    }
    return 0;        
    }
};
