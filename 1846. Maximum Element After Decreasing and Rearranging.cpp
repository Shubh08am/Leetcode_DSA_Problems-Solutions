class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
       int maxNo = 0;
       sort(arr.begin(),arr.end());
        for(auto it : arr){ 
            //assign min at ith position
             maxNo =min(maxNo+1 ,it) ;
            }
       return maxNo;
    }
};
