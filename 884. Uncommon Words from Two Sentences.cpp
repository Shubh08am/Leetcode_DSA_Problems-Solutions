class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        vector<string>ans;
        s1+=' ';s2+=' ';
        string curr = "";
        map<string,int>s,ss;
        for(int i=0;i<s1.size();i++){
           if(s1[i]==' ') s[curr]++,curr="";
           else curr+=s1[i];
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' ') ss[curr]++,curr="";
           else curr+=s2[i];
        }
        for(auto&it:s){
            if(!ss.count(it.first) && it.second==1) ans.push_back(it.first) ;
        }
        for(auto&it:ss){
            if(!s.count(it.first) && it.second==1) ans.push_back(it.first) ;
        }
    return ans;
    }
};
