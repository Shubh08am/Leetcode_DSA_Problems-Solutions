class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
     string ans="";
        map<string,int>m;
        m[s]++;
        for(auto val : words )
        {
            ans+=val;
            if(m.find(ans) != m.end())
            {
                return true;
            }
        }
        return false;   
    }
};
