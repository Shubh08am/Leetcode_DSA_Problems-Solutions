class Solution {
public: 
    bool ispal(string&s){ 
    int i=0;
      while(i<s.size()>>1){
    if(s[i]!=s[s.size()-1-i]) return false;  
          i++;
          }
     return true ;   
        }
    string firstPalindrome(vector<string>& words) {
       
   for(auto& it:words){
       if(ispal(it)){ return it;}
    }
      return ""; 
        }
};
