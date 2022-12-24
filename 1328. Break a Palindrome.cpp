class Solution {
public:
    string breakPalindrome(string palindrome) {
          int n=palindrome.size();

       if(n==1) {return "";}
     //ex:- bac -> aac
      for(int i=0;i<n/2;++i){
         if(palindrome[i]!='a'){
        palindrome[i]='a';
           return palindrome;
                     } 
      }
       //ex:- aaa ->aab 
      palindrome[n-1]='b';
      return palindrome;      
    }
};
