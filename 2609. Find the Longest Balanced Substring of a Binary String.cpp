class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        stack<int>st;
        int c=0 , a=0; 
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')  st.push(0) ; 
            else{
                if(st.empty()) continue; 
                while(!st.empty() && st.top()==0 && s[i]=='1'){
                    a+=2;
                    st.pop();
                   i++;
                }
                c=max(a,c);
                a=0;
              i-=1;
                while(!st.empty()) st.pop() ;
             //   cout<<st.size()<<"\n" ; 
            }
        }
        return c;
    }
};
