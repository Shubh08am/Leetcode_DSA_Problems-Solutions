class Solution {
public:
    int romanToInt(string s) {
     //    string a = "IV";
     //  string b = "IX";
     // string c = "XL";
     // string d = "XC";
     // string e = "CD";
     // string f = "CM";
int ans=0;
        bool f=0;
        
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == 'I' and s[i+1]=='V') {ans+=4; i++;
                                             if(i==s.size()-1) {;f=1;}}
            else if(s[i] == 'I' and s[i+1]=='X') {ans+=9; i++;
                                                   if(i==s.size()-1){f=1;}}
            else if(s[i] == 'X' and s[i+1]=='L') {ans+=40; i++;
                                                   if(i==s.size()-1) {f=1;}}
             else if(s[i] == 'X' and s[i+1]=='C') {ans+=90; i++;
                                                    if(i==s.size()-1){f=1;}}
             else if(s[i] == 'C' and s[i+1]=='D') {ans+=400; i++;
                                                    if(i==s.size()-1) {f=1;}}
             else if(s[i] == 'C' and s[i+1]=='M') {ans+=900; i++;
                                                    if(i==s.size()-1) {f=1;}}
            
            else if(s[i]=='I') ans+=1;
        else if(s[i]=='V') {ans+=5;}
        else if(s[i]=='X') ans+=10;
    else if(s[i]=='L') ans+=50;
            else if(s[i]=='C') ans+=100;
            else if(s[i]=='D') ans+=500;
   else if(s[i]=='M') ans+=1000;
        } 
        
       if(!f){
           int i=s.size()-1;
          // cout<<"yr";
             if(s[i]=='I') ans+=1;
        else if(s[i]=='V') ans+=5;
        else if(s[i]=='X') ans+=10;
    else if(s[i]=='L') ans+=50;
            else if(s[i]=='C') ans+=100;
            else if(s[i]=='D') ans+=500;
   else if(s[i]=='M') ans+=1000;
       }
        return ans;
    }
};
