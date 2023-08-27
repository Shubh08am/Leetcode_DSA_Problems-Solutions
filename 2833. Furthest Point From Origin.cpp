class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l = count(s.begin(),s.end(),'L') ;
        int r = count(s.begin(),s.end(),'R') ;
        int _ = count(s.begin(),s.end(),'_') ;
        return s.size()-2*min(l,r);
    }
};
