class Solution {
public:
    int minChanges(string s) {
        int n=s.size() ; 
        int c= count(s.begin(),s.end(),'0') ; 
         int cc= count(s.begin(),s.end(),'1') ;
        if(c==n || cc==n) return 0; 
        int b=0;
        for(int i=0;i<n-1;i+=2){
            if(s[i]!=s[i+1]) b++;
            
        }
           return b;
    }
};
