class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size() ; 
        vector<int>p(n) ;
        int val=0;
        p[0]=pref[0];
        for(int i=0;i<n-1;i++){
            p[i+1] = pref[i]^pref[i+1] ;
           // cout<<val<<" ";
            //p.push_back();
        }
        
        
        return p ;
    }
};
