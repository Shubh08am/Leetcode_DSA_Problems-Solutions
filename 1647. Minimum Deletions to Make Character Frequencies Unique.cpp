class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0) ;
        unordered_set<int> occ; 
        int ans = 0 ;
        for(auto & ch : s) freq[ch-'a']++; 
        // ith char kii x time freq ko x-1 , x-2 , .... , 0 tak leke jaao 
        for(int i=0;i<26;i++){
            while(freq[i]>0 && occ.count(freq[i])) freq[i]--,ans++; 
            occ.insert(freq[i]) ;
        }
    return ans;
    }
};
