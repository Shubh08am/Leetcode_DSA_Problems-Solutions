class CombinationIterator {
public:
    map<int,set<string>>mp; int cl = 0 ;
    //generate all subsequences 
    void subsequences(int index , string characters , string &s,int n){
        //if reached end 
        if(index==n){
        //    cout<<s<<" ";
            mp[s.size()].insert(s);
            return;
        }
        //take 
        s+=characters[index];
        subsequences(index+1,characters,s,n);
        s.pop_back(); //backtrack 
        //not take 
        subsequences(index+1,characters,s,n);
    }
    CombinationIterator(string characters, int combinationLength) {
        //generate all string of combinationLength 
        int n=characters.size() ;
        cl = combinationLength ; 
        string s="";
        //generate all subsequences 
        subsequences(0,characters,s,n);
    }
    
    string next() {
         string ans = *(mp[cl].begin()) ; 
         mp[cl].erase(ans);
         return ans;
    }
    
    bool hasNext() {
        return !mp[cl].empty() ;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */ 
