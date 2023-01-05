class Solution {
public:
    string reverseWords(string s) {
  int n=s.size(); 

        if(n == 1)
            return s;

     int i=n-1;

     while(i > 0){

         while(i >= 0 && s[i] == ' '){
             i--;
         }

         int size = 0;
         while(i >= 0 && s[i] != ' ') {
             i--;
             size++;
         }

         s += s.substr(i+1,size);
         s += " ";

     }

     s.erase(0,n);

     int e = s.size()-1;
     while(s[e] == ' '){ 
         e--;
    }
    
     return s.substr(0,e+1);         
    }
};
