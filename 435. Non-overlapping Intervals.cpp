class Solution {
public: 
    static bool cmp(vector<int>&first, vector<int>&second){
    if(first[1] == second[1]) return first[0]<second[0];
    return first[1]<second[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int OverlapIntervals = 0 , intervalCheck=0 , n = intervals.size(); 
        sort(intervals.begin(),intervals.end(),cmp);
    //   for(auto it : intervals) for(auto x:it) cout<<x<<" ";
    //    cout<<"\n";
        bool found = 0 ; 
        for(int i=0;i<n-1;i++){
            intervalCheck = i ; 
            while(intervalCheck+1<n  && intervals[i][1]>intervals[intervalCheck+1][0]){
                OverlapIntervals++;
               intervalCheck++;
       //     cout<<intervalCheck<<"\n";
               found=1;
            }
            //update i 
           if(found) i=intervalCheck;
        //   cout<<intervalCheck<<" "<<i<<"\n";
        }
        return OverlapIntervals;
    }
}; 
