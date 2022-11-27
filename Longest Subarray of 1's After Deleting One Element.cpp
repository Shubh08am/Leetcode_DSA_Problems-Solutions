class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>zero;
        int n = nums.size() ;
        int ans=0;
        int possible_ans=0 , anss=0 , res=INT_MIN , frst=0;
   
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero.push_back(i) ; 
        }
        
        if(zero.size()==n) {
            return 0 ;
        }
        else if(zero.size()==0) {
            return n-1;
        }
       else if(zero.size()==1) {
            return n-1;
        }
        
         else if(zero.size()==n-1) {
            return 1;
        }
        
        else{
            frst = zero[1]-1 ;
            for(int i=1;i<zero.size()-1;i++){
                    possible_ans = zero[i+1]-zero[i-1]-1 -1;
                
                res=max(res,possible_ans);
            }
             anss = n-zero[zero.size()-2]-1-1;
             res=max(res,possible_ans);
            res=max(res,frst);
            res=max(res,anss);
        }
        return res;
    }
};
