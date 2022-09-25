class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       
        int f_m = 0;
        int f_g=0;
        int f_p = 0 ;
        int n = garbage.size();
        bool f=0; bool ff=0; bool fff=0;
        
        for(int i=n-1;i>=0;--i){
            string s = garbage[i]; //cout<<s<<endl;
            for(int j=0;j<s.size();j++){if(s[j]=='G')  {f=1 ; f_g=i; } }
            if(f==1) {break;}
        }
        
        for(int i=n-1;i>=0;--i){
            string s = garbage[i]; //cout<<s<<endl;
            for(int j=0;j<s.size();j++){if(s[j]=='P')  {ff=1 ; f_p=i; } }
            if(ff==1) {break;}
        }
        
        for(int i=n-1;i>=0;--i){
            string s = garbage[i]; //cout<<s<<endl;
            for(int j=0;j<s.size();j++){if(s[j]=='M')  {fff=1 ; f_m=i; } }
            if(fff==1) {break;}
        }
        
        //cout<<f_g<<endl;cout<<f_p<<endl;cout<<f_m<<endl;
        
        int t_g=0; int t_p=0; int t_m=0; 
        int total_time = 0;
        
        for(int i=0;i<f_g;i++) {
            t_g+=travel[i];
        }
        
         for(int i=0;i<f_p;i++) {
            t_p+=travel[i];
        }
        
        
         for(int i=0;i<f_m;i++) {
            t_m+=travel[i];
        }
        
      for(int i=0;i<=f_g;i++) {
        string s = garbage[i] ; 
          for(int i=0;i<s.size();i++){ if(s[i]=='G')  { t_g++; } }
        }
        
        for(int i=0;i<=f_p;i++) {
        string s = garbage[i] ; 
          for(int i=0;i<s.size();i++){ if(s[i]=='P')  { t_p++; } }
        }
        
        for(int i=0;i<=f_m;i++) {
        string s = garbage[i] ; 
          for(int i=0;i<s.size();i++){ if(s[i]=='M')  { t_m++; } }
        }
        
        total_time = t_g + t_m + t_p ;
        
        return total_time;
    }
};
