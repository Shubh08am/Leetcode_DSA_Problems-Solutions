class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(),pairs.end(),[&](auto&a,auto&b){return a[1]<b[1];});
         int n=pairs.size(),last=INT_MIN,ans=0;
       //[a,b] [c,d] [e,f] -> b<c && d<e 
       // pairs[i][1] compared with pairs[i][0] and store last end point i.e pairs[i][1]
        for(int i=0;i<n;i++){
            if(pairs[i][0]>last){
                ans++;
               last = pairs[i][1];
            }
        }
    return ans;
    }
};
