class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

    multiset<int> s;
    s.insert(intervals[0][1]);
    
    for(int i=1; i<intervals.size(); i++){
     // overlapping occurs make a new group    
        if(*s.begin() >= intervals[i][0] ){    
            s.insert(intervals[i][1]);
        }
        // no overlapping 
        else{
            s.erase(s.begin()); //delete it
            // now insert y co-ordinate
            s.insert(intervals[i][1]);     
        }
    }
    int ans = s.size();
    return ans ;  
        
    }
};
