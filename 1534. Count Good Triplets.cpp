class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
int n = arr.size();
int cnt = 0;

      for(int i=0;i<n-2;i++) {
      for(int j=i+1;j<n-1;j++) {
      for(int k=j+1;k<n;k++) {
      int val1 =  abs(arr[i]-arr[j]);
      int val2 = abs(arr[j]-arr[k]);
      int val3 = abs(arr[i]-arr[k]);

      if(val1<=a&& val2<=b&& val3<=c){cnt++;}
       }}}
       return cnt;        
    }
};
