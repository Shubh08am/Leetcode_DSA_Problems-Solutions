class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
      //  for(auto&it:intervals){
     //    for(auto x:it) cout<<x<<" ";
     //   }
        int n = intervals.size(),cnt=1;
 
        for(int i=0;i<n-1;i++){
            if(intervals[i][1]>=intervals[i+1][1]){
                 intervals[i+1][1]=intervals[i][1];
            }
            else {
            //    cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};
