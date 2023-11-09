class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string &a,string&b){
            return a.size() < b.size() ;
        });
        string a = words[0];
        map<char,int>mp,pm,pmp;
         for(char ch='a';ch<='z';ch++) pmp[ch]=INT_MAX;
        for(auto it : a) pm[it]++;
      //  cout<<a<<"\n";
        int n=words.size(); 
        for(int i=1;i<n;i++){
           // cout<<words[i]<<" ";
            for(auto&it:words[i]) mp[it]++;
            for(char ch='a';ch<='z';ch++){
                if(pm[ch] && mp[ch]){
                    pmp[ch]=min({pmp[ch],pm[ch],mp[ch]});
                }
                else{
                    pmp[ch]=0;
                }
            }
            mp.clear();
        }
        vector<char>ans;
        for(auto &it : pmp) {
            if(it.second) {
                char ch = it.first;
                int cnt=it.second;
             //   cout<<it.second<<" "<<it.first<<"\n";
              while(cnt--) ans.push_back(ch);
            }
        }
        vector<string>ap(ans.size()); 
        for(int i=0;i<ans.size();i++) ap[i]=ans[i];
    return ap;
    }
};
