class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size() ; 
        double ans = 0 ; 
        int remove = n*5/100; 
        sort(arr.begin(),arr.end()) ; 
        for(int i=remove;i<n-remove;i++){
            ans+=arr[i];
        }
        return ans*1.0/(n-2*remove) ; 
    }
};
