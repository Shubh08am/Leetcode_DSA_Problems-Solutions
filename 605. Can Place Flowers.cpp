class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
     int cnt = 0 , l =  flowerbed.size();

        for(int i = 0; i<l ;  i++){
            bool lo = false, ro = false;
            if(!flowerbed[i]){
                if(i == 0 || !flowerbed[i-1]){
                    lo = true;
                }
                if(i==l-1 || !flowerbed[i+1]){
                    ro = true;
                }
                if(lo && ro){
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
        }
        return cnt>=n;
    }
};
