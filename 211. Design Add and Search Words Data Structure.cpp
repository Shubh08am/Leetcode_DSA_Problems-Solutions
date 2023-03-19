class WordDictionary {
public:
    vector<string>ans;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        ans.push_back(word);
    }
    
    bool search(string word) {
        int similarChar=0, n=word.size() , m=ans.size();
        for(int i=0; i<ans.size(); i++){
            //if word and ans[i] size not equal than they can't be same 
           //  string curr = ans[i] ; //-> this lines gives tle when included
           //  cout<<curr<<" "<<ans[i]<<"\n";
            if(n!=ans[i].size()) continue;
                for(int j=0; j<n; j++){ 
                    //we assume '.' to be same as char[j] as we can fill them later on 
                    if(ans[i] [j]==word[j] || word[j]=='.'){
                        similarChar++;
                    }
                    else  {
                        similarChar=0;
                        break;
                    }
                }
                //search result on that word failed if similarChar not equal to word size
                if(similarChar==n) return true;
        }
         return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
