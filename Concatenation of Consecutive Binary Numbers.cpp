class Solution {
public:
    
  string DecimalToBinary(int num){
    string str="";
      while(num){
      if(num & 1)
        str+='1';
      else  str+='0';
      num>>=1; 
    }   
     reverse(str.begin(),str.end()) ;
      return str;
}
 
    
 int concatenatedBinary(int n) {
      int mod = 1e9+7;
        string ans="";
        for(int i=1;i<=n;i++){
    ans+=(DecimalToBinary(i)) ;
        }
      long long int result = 0 , r;  
     unsigned long long int two = 1;
    for(int i=ans.size()-1;i>=0;--i){
        result= ((result%mod)+(ans[i]-'0')*(two%mod))%mod;
    r = ((two*2*1LL)%mod) ;
        two = r;
    }
        return result;      
    }
};
