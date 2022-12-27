class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
           string max_time = max(event1[0], event2[0]) ;
           string min_time =  min(event1[1], event2[1]);
        
        //for interesection to happen
           if(max_time<=min_time) return true;
        
           return false;
    }
};
