class Solution {
public:
    int n=0;vector<int>prefix;
    Solution(vector<int>& w) {
        n=w.size();
        prefix.resize(n) ; //resizes to size of n 
        prefix=w;
        for(int i=0;i<n-1;i++){
         prefix[i+1]+=prefix[i];
    //     cout<<prefix[i]<<" ";
        }
    //    cout<<prefix[n-1]<<" ";
    }
    
    int pickIndex() {
       int val= rand()%prefix[n-1];
       int index = upper_bound(prefix.begin(),prefix.end(),val) - prefix.begin() ;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
