class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //binary search 
        int n = houses.size() , m = heaters.size() , radius = 0; 
        sort(houses.begin(),houses.end()) ; 
        sort(heaters.begin(),heaters.end()) ;

        for(int i=0;i<n;i++){
            int pos = lower_bound(heaters.begin(),heaters.end(),houses[i]) - heaters.begin() ; 
            int ahead = 1e9 , prev = 1e9;

            if(pos!=m){
                ahead = heaters[pos] - houses[i] ;
            }
            if(pos>0){
                prev= houses[i] - heaters[pos-1] ;
            }
            int where = min(ahead,prev);
            radius=max(radius,where);
        }
    return radius;
    }
};
