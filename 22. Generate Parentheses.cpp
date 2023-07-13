class Solution {
public:
    void solve(int open,int close,int n,string str, vector<string>&ans){
        if(open==n&&close==n){
            ans.push_back(str);
            return;
        }
        //Call for opening bracket till n open bracket obtained 
        if(open<n){
            str.push_back('(');
            solve(open+1,close,n,str,ans);
            str.pop_back();
        }
         //Call for closing bracket when less closing bracket than open bracket 
        if(close<open){
            str.push_back(')');
            solve(open,close+1,n,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       solve(0,0,n,"",ans);
       return ans; 
    }
};
