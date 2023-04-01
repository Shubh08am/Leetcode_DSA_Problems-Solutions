class MagicDictionary {
public:
//trie -> Optimized Approach 
unordered_map<string,int>m; //brute force
    bool differ(string s1,string s2){
        int diff=0;
       // cout<<s1<<" "<<s2<<"\n";
        if(s1==s2 || s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();i++) {
            if(s1[i]!=s2[i]) {
                diff++;
                //cout<<s1<<" "<<s1[i]<<" "<<s2<<" "<<s2[i]<<"\n";
            }
        }
        return diff==1;
    }
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
       for(auto it : dictionary) m.insert({it,1});
    }
    
    bool search(string searchWord) {
         //traverse across map and compare always 
         bool flg=false;
         for(auto it : m){
            flg =  differ(it.first,searchWord);
            if(flg) return true;
         }
         return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
