class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<long long>prefix;
        //Taking first Prefix Sum 
        for(int i=0;i<n;i++){
            if(i==0)prefix.push_back(nums[i]) ; 
            else prefix.push_back(nums[i]+prefix.back()) ; 
        }
       // for(auto&it: prefix) cout<<it<<" ";

        //Run a Loop from kth position to n-k-1th position 
        vector<int>radius(n,-1);
        
        for(int i=k;i<=n-k-1;i++){
            long long contribution = prefix[i+k] ; 
            long long  prev_Contribution = 0 ; 
            long long  curr_Radius = 0 ;
            //Removing prev_Contribution 
            if(i-k!=0){
                 prev_Contribution = prefix[i-k-1];
            }
            curr_Radius = (contribution-prev_Contribution)/(1+2*k) ; 
            radius[i] = curr_Radius;
        }
    return radius;
    }
};
