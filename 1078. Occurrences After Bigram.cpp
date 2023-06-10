class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text+=' '; 
        string s="";
        vector<string>curr,ans;
        for(auto&ch:text){
             if(ch!=' '){
                s+=ch;
            }
            else{
                curr.push_back(s);
                s="";
            }
        }
        for(int i=0;i<curr.size()-2;i++){
            if(curr[i]==first && curr[i+1]==second) ans.push_back(curr[i+2]);
        }
    return ans;
    }
};
