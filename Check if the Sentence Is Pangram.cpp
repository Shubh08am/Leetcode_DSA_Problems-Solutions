class Solution {
public:
    bool checkIfPangram(string s) {
    // method 1
        /*   sort(s.begin(),s.end()); 
        int n = 0;  
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[i+1]) n++;
        }   
        return n==26; 
   */     
        // using set 
    /*
        set<char>se;
        se.insert(s.begin(),s.end());
        
        return se.size()==26;
     */   
        
          // using unordered set 
    
        unordered_set<char>se;
        se.insert(s.begin(),s.end());
        
        return se.size()==26;
     
    }
};
