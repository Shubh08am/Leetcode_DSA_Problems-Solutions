class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=0 , i=0,j=0 ; 
       /* vector<int> v , a , c;
        
        for(int j=0 ; j<s.size();j++){ 
        for(int i=0; i<t.size() ; i++) {
            if(s[j]==t[i]){ cnt++;
              v.push_back(j);
                a.push_back(i);           
                          } }}
            c = a ; 
            sort(c.begin(),c.end()) ; 
            for(int i=0;i<s.size();i++){
                if(c[i]==a[i]) cn++;
            } 
        
        if(s.size()==0 && t.size()==0 )  return false;
        
            else if(v.size()!=s.size() || cnt!=s.size()) 
                return false;
            
            else if( cn==s.size()) 
                return true;
        */
      while(j<t.size())
      {
        if(s[i]==t[j])
        {
          cnt++;
          i++;
          
        }
        j++;
      }
      
     return (cnt ==s.size()); 
    }
};
