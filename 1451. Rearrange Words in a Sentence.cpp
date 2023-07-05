class Solution {
public:
    char lower(char ch){
        char low = ch;
        if(ch>='A' && ch<='Z') {
            low = ((ch-'A')+'a');
        }
    return low;
    }
    char upper(char ch){
        char up = ch;
        if(ch>='a' && ch<='z') {
            up = ((ch-'a')+'A');
        }
    return up;
    }
    string arrangeWords(string text) {
        text+=' ';
        vector<pair<string,int>>vp;
        int pos=0;string curr="";
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                vp.push_back({curr,pos++});
                curr="";
             }
            else //cout<<lower(text[i])<<" ",
            curr+=lower(text[i]);
        }
       
        sort(vp.begin(),vp.end(),[&](pair<string,int>&a,pair<string,int> &b){
        if(a.first.size()<b.first.size()) return 1;
        else if(a.first.size()==b.first.size()){
          //  cout<<a.first<<" "<<b.first<<"\n";
          //  cout<<a.second<<" "<<b.second<<"\n";
            if (a.second>b.second ) return 0;
            else return 1;
        }
        else return 0;
        });

       /* for(auto&it:vp) {
            cout<<it.first<<" ";
        }*/

        string ans="";
        for(auto&it:vp) {
            ans+=it.first;
            ans+=" ";
        }
        ans[0] = upper(ans[0]) ;
        ans.pop_back(); 
     return ans;
    }
};
