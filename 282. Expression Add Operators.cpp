#define ll long long
class Solution {
public:
    void solve(int ind,vector<string>&ans,string num, int target,string path,ll res , ll prev_res){
        ll n = num.size();
        if(ind==n && res==target){
            ans.push_back(path);
            return;
        }

        ll curr_num=0;
        string rem="";

        //form remaining string 

        for(ll i=ind;i<n;i++){
            rem+=num[i];
            curr_num=curr_num*10+(num[i]-'0');

            //LEADING 0 STRING SKIPPED
            if(rem.size()>1 && rem[0]=='0') break;

            //FOR 0TH POS ONLY TAKE NUMBER AND NO OPERATORS
            if(ind==0){
                solve(i+1,ans,num,target,rem,curr_num,curr_num);
            }
            //FOR 1ST POS ONWARDS DO 3 CALLS FOR +,-,*
            else{
                 // +
                solve(i+1,ans,num,target,path+"+"+rem,res+curr_num,curr_num);
                 // -
                solve(i+1,ans,num,target,path+"-"+rem,res-curr_num,-curr_num);
                 // *
                solve(i+1,ans,num,target,path+"*"+rem,(prev_res*curr_num)+res-prev_res,curr_num*prev_res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        //RECURSION + BACKTRACKING 
        vector<string>ans;
        solve(0,ans,num,target,"",0,0);
        return ans;
    }
};
