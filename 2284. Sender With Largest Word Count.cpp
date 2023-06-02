class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>s; 
        int n=messages.size(),maxWord=0;
        string ans="";
        
        for(int i=0;i<n;i++){
            int wordCnt = 1 + count(messages[i].begin(),messages[i].end(),' ') ; 
            s[senders[i]]+=wordCnt;
        } 
        
        for(auto&it:s){
            if(it.second>=maxWord){
                maxWord=it.second;
                ans=max(ans,it.first) ;
            }
        }
        return ans;
    }
};
