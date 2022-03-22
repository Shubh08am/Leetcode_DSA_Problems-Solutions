class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
            map<char,bool> mp;
        for(auto ch : allowed) {
            mp[ch] = true;
        }
        int res = 0;
        for(auto s : words) {
            bool ch = true;
            for(auto it : s) {
                if(!mp[it]) {
                    ch = false;
                    break;
                }
            }
            if(ch) res++;
        }
        return res;
    }
};
