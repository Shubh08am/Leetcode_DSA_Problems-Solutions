class Solution {
public:
    //AGGRESSIVE COWS 
    bool isPossible(int mid,vector<int>&price,int k){
        int last = price[0] , req=1; 
        for(int i=1;i<price.size();i++){
            if(price[i]-last >= mid){
                req++;
                last=price[i];
            }
            if(req>=k) return 1;
        }
    return 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end()) ; 
        int n=price.size();
        int low=1,high= price[n-1]-price[0],ans=0;
        while(low<=high){
                int mid = low+(high-low)/2;
                if(isPossible(mid,price,k)){
                    low=mid+1;
                    ans=mid;
                }
                else high=mid-1;
        }
    return ans;
    }
};
