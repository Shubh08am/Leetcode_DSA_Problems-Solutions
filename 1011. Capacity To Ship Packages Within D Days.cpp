class Solution {
public:
    bool isPossible(int mid,vector<int>& weights, int days) {
        int sum=0,req=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                req++;
                sum=weights[i];
            }
            else sum+=weights[i];
        }
    return req<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(),weights.end())  ; 
       int high = accumulate(weights.begin(),weights.end(),0) ; 
        int ans=0;
       while(low<=high){
           int mid = low + (high-low)/2; 
           if(isPossible(mid,weights,days)){
               high=mid-1;
               ans=mid;
           }
           else low=mid+1;
       } 
    return ans;
    }
};
