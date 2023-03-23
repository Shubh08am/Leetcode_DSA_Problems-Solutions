class Solution {
public: 
     string d(int n){
    string s;
      while(n){
      if(n & 1) 
        s+='1';
      else  s+='0';
      n>>=1; 
    }   
      return s;
}
    vector<int> evenOddBit(int n) {
        string s = d(n) ; 
        vector<int>v;  
             int o=0,e=0;
   //     cout<<s<<"\n";
        for(int i=0;i<s.size();i++){
if(s[i]=='1'){
    if(i&1) o++;
    else e++;
}}
            return {e,o};
        
    }
};
