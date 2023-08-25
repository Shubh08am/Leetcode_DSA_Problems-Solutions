class Solution {
public:
    bool isAcronym(vector<string>& w, string s) {
        string p = ""; 
        for(auto&i:w) p+=i[0] ; 
        return p==s;
    }
};
