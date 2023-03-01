class Solution {
public:
    bool backspaceCompare(string s, string t) {
         stack<char> s1, s2;
        for(auto &x:s){
            if(x=='#' && !s1.empty()) s1.pop();
            else if(x=='#' && s1.empty()) continue;
            else s1.push(x);
        }
        for(auto &x:t){
            if(x=='#' && !s2.empty()) s2.pop();
            else if(x=='#' && s2.empty()) continue;
            else s2.push(x);
        }
         return s1==s2;
    }
};
