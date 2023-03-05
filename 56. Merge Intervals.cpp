class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        for(int i=0;i<n;i++){
             //if ans is empty 
             if(ans.size()==0){
              ans.push_back(intervals[i]);
             }
             //overlapping intervals
            //after that compare intervals[i][0] and ans[ans.size()-1][1] 
            if(ans.size()>0 && ans[ans.size()-1][1] >=  intervals[i][0]){
                //now,merge and update ans[ans.size()-1][1] to max of ans[ans.size()-1][1] & intervals[i][1]
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],intervals[i][1]) ; 
            } 
            //non-overlapping intervals 
            if(ans.size()>0 && ans[ans.size()-1][1] <  intervals[i][0]){
                 ans.push_back(intervals[i]);
            }
         }
        return ans ;  
    }
};
