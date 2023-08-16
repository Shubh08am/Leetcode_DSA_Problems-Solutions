class Solution {
public:
    //T.C -> O(3^N * N [FOR FINDING SUB-STRING PART]) -> 3 POSSIBILITIES EVERY TIME AT MAX 3 LENGTH IN A PART 
    void solve(int ind,int part,string &s,string curr,vector<string>&ans){
        int n = s.size() ; 
        if(ind==n){
            if(part==4){
                curr.pop_back(); //remove last '.' 
                ans.push_back(curr) ;
            }
            return;
        }

        string check = "";
        int value = 0 ;
        for(int i=ind;i<min(ind+3,n);i++){
            check+=s[i] ; 
            value=value*10 + (s[i]-'0') ; 
            //ONE LENGTH STRING WORKS NO CHECK 
            //ELSE CHECK VALUE <=255 AND NO LEADING ZEROS
            if((value<=255 && check[0]!='0') || check.size()==1){
                solve(i+1,part+1,s,curr+check+'.',ans);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        //s of length > 12 no valid IP Addresses exists
        vector<string>ans ; 
        solve(0,0,s,"",ans) ; 
        return ans ;
    }
};
