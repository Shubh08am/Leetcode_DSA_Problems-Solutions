class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid, int m, int k){
        int days=0,canBloom=0;
        for(auto&it:bloomDay){
            if(it<=mid) days++;
            else{
                canBloom+=days/k;
                days=0;
            }
        }
        canBloom+=days/k;
    return canBloom>=m;;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=*min_element(bloomDay.begin(),bloomDay.end()),e=*max_element(bloomDay.begin(),bloomDay.end()) , f=e; 
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(bloomDay,mid,m,k)){
                e=mid-1;
            }
            else s=mid+1;
        }
    return s>f?-1:s;
    }
};
