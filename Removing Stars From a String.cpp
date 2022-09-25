class Solution {
public:
    string removeStars(string S) {
  stack<char>st;
string ans = "";
	for(int i= 0;i<S.size();i++){
if(S[i]!='*') st.push(S[i]);
else if(S[i]=='*' and i!=0){
 st.pop();
}
	}
	

while(!st.empty()){
ans.push_back(st.top());
st.pop();
} 
reverse(ans.begin(),ans.end());
return ans;      
      
      //method 2
      string ans = "";
        	for(int i= 0;i<S.size();i++){
if(S[i]=='*') {
	ans.pop_back();
} 
                else {  
                    ans+=S[i];
	} 
            }
return ans;
    }
};
