class Solution {
public:
    void solve(int ind,string letter,string digits,vector<string>&phoneNo,vector<string>&alphabets){
        int n = digits.size();
        if(ind==n){
            phoneNo.push_back(letter);
            return;
        }
        for(int i=0;i<alphabets[digits[ind]-'0'].size();i++){
            letter+=alphabets[digits[ind]-'0'][i];
            solve(ind+1,letter,digits,phoneNo,alphabets);
            letter.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string>alphabets(10,""),phoneNo; 
       alphabets[2]="abc" ;  alphabets[3]="def" ; alphabets[4]="ghi" ; alphabets[5]="jkl" ;  
       alphabets[6]="mno" ;  alphabets[7]="pqrs" ;  alphabets[8]="tuv" ; alphabets[9]="wxyz" ; 
    solve(0,"",digits,phoneNo,alphabets);
    if(digits.size()==0) return {};
    return phoneNo;
    }
};
