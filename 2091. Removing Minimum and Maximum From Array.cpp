class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX , mx = INT_MIN , n = nums.size();
        int pos_mn = -1 , pos_mx = -1 ; 
        int req = n ; 

        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=nums[i] ; 
                pos_mn=i;
            }
            if(nums[i]>mx){
                mx=nums[i] ; 
                pos_mx=i;
            }
        }

        int ans1 = max(pos_mn,pos_mx) + 1 ;
        req = min(req,ans1) ;

        int max_back = n - pos_mx ; 
        int min_back = n - pos_mn ; 

        int ans2= max(max_back,min_back) ;
        req = min(req,ans2) ;

        int ans3= min(pos_mn+1,min_back) ;
        int ans4= min(pos_mx+1,max_back) ;
        req = min(req,ans3+ans4);
        
    return req;
    }
};
