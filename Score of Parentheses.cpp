class Solution {
public:
    int scoreOfParentheses(string s) {
   int n = s.size();
        stack<int>st;
        
        int cnt=0 , c=0;
        
        for(int i=0 ; i<n;i++){
            if(s[i]=='(') {
                st.push(cnt); 
                cnt=0;
            }
 
            else if (s[i]==')')  {
               cnt= st.top()+max(cnt*2,1);
                st.pop() ;
            }
            
        }
        
        return cnt;
        
    }
};
