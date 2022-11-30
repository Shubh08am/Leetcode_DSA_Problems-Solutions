class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0; 
        if(rungs[0] > dist)  ans+=(rungs[0]-1)/dist;
        
        for(int i=0;i<rungs.size()-1;i++){
            int val = rungs[i+1]-rungs[i] ; 
            if(val>dist) ans+=(val-1)/dist ;
        }
        return ans;
    }
};
