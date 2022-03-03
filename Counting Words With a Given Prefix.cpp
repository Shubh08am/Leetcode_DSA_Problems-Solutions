class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt = 0, i, m = pref.size();
        for (i = 0; i < words.size(); ++i){
            if (words[i].substr(0, m) == pref) cnt++;
    }
        return cnt;
        
    }
};
