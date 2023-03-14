class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans = true;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{'|| s[i] == '['){
                st.push(s[i]);
            }
            else if(!st.empty() && s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else
                    return false;
            }
            else if(!st.empty() && s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else
                    return false;
            }
            else if(!st.empty() && s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else
                    return false;
            }
            else{
                ans = false;
            }
        }
        if(!st.empty()){
            return false;
        }
        return ans;
    }
};
