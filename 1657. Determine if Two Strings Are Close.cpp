class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>m1,m2;
        vector<int>v1,v2;
        for(auto it : word1) m1[it]++;
        for(auto it : word2) m2[it]++;

        if(word1.size()!=word2.size()) return false;
 
 //v1 contains frequency of all character of m1
      for(auto it : m1){
      v1.push_back(it.second);
        }
 //v2 contains frequency of all character of m2
        for(auto it : m2){
       v2.push_back(it.second);
        }
        
        //character of m2 doesn't exist in m1
        for(auto it:m2){
            if(m1.find(it.first)==m1.end()){
                return false;
            }
        }

 //store the occurence in v1 and v2 and than compare max --> O(26*26)
        //all characters of m2 exist in m1 than see for frequency 
        for(int i=0;i<v1.size();i++){
            bool flg=0;
            for(int j=0;j<v2.size();j++){
                //character should exist in m1
            if(v1[i]==v2[j]){
                v2[j]=-1;
                flg=1;
                break;
            }
            if(flg) continue;
        }
       if(flg==0) return false;
        }
        return true;
    }
};
