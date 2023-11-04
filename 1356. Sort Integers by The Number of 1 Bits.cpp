class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int seta = __builtin_popcount(a) ; 
            int setb = __builtin_popcount(b) ;
            return seta==setb?a<b:seta<setb; 
        }) ; 
    return arr;
    }
};
