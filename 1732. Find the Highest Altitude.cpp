class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0 , curr = 0 ; 
        for(auto&gainOfAltitude : gain){
            curr+=gainOfAltitude;
            altitude = max(altitude , curr) ; 
        }
    return altitude;
    }
};
