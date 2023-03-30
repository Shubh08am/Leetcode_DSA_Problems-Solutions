class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int>st;
       st.push(-1);
       int n = s.size() , valid=0 ; 
       for(int i=0;i<n;i++){
           if(s[i]=='(') st.push(i) ; //open bracket
           else{
           //close bracket 
        st.pop();
        if(st.empty()) st.push(i);
        int currLen = i-st.top() ; 
        valid=max(valid,currLen);
           }
       }
       return valid;
    }
};
