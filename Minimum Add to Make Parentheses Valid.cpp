class Solution {
public:
    int minAddToMakeValid(string s) {
   int ans = 0 ; 
        // ( ( ( ))) -> 0
        // ( ))) --> 2 
        // (( ) --> 1
        stack<char>st ; 
        for(int i=0;i<s.size();i++){
if(s[i]=='(') st.push(s[i]);    
            
            else if(s[i]==')'){
                if(st.empty()) ans++;
                else {
                    st.pop();
                }
            }
        }
ans+=st.size();
        
        return ans;     
    }
};
