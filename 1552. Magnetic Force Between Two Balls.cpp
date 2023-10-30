class Solution {
public:
    bool isPossible(int mid,vector<int>& position, int m) {
        int cnt=1,n=position.size(),prev=position[0];
        for(int i=1;i<n;i++){
            if(position[i]-prev>=mid){
                cnt++;
                prev=position[i];
            }
            if(cnt>=m) return true;
        }
    return false;
    }
    int maxDistance(vector<int>& position, int m) {
        //binary search on answer -> Aggressive cow technique
        sort(position.begin(),position.end());
        int n = position.size() , low = 1 , high=position[n-1]-position[0],ans=0;
        while(low<=high){
            int mid = low+((high-low)>>1);
            if(isPossible(mid,position,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    //opposite polarities -> high
    return low-1;//return high; // return ans;
    }
};
