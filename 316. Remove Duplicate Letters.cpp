class Solution {
public:
    string removeDuplicateLetters(string s) {
        /*
        Track occurence of each character use last occurence and use stack
        */
        unordered_map<char,int>lastPos,vis;
        stack<char>word;
        int size = s.size();
        for(int i=0;i<size;i++){
            lastPos[s[i]]=i;
        }
        for(int i=0;i<size;i++){
            if(vis[s[i]]) continue;

            //if multiple occurence of a larger character remove earlier occurence
            while(!word.empty() && word.top()>s[i] && i<lastPos[word.top()]){
                vis[word.top()]=0;//as multiple occurence of this character
                word.pop();
            }
            word.push(s[i]);
            vis[s[i]]=1;
        }
        string ans="";
        while(!word.empty()){
            ans=word.top()+ans;
            word.pop();
        }
    return ans;
    }
};
