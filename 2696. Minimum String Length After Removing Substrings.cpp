class Solution {
public:
    int minLength(string s) {
         stack<char>st; 
        int n = s.size() ; 
        st.push(s[0]);
        for(int i=1;i<n;i++){
            bool f=0;
            
            if(!st.empty() && st.top()=='A' && s[i]=='B') {f=1;st.pop() ; }
             if(!st.empty() && st.top()=='C' && s[i]=='D') {f=1 ; st.pop() ; }
            
           if(!f)   st.push(s[i]) ;
        }
        return st.size() ; 
    }
};
