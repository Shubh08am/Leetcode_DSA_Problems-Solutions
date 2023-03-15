class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>freq,mp;
        string s = word1+word2;
        for(auto& it : word1) freq[it]++;
        for(auto& it : word2) {
             mp[it]++;
        }
        for(auto&it : s) { 
             if(abs(mp[it]-freq[it])>3) return false;
        }
        return true;
    }
};
