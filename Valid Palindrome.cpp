
class Solution {

public:

    char Lower (char sh){

        if(sh>='a' && sh<='z' ){

            return sh;

        }

        return sh-'A'+'a' ;

    }

    

    bool isPalindrome(string s) {

        

        string T="";

        

        for(int i=0;i<s.length();i++){

            if((s[i]>='a' && s[i]<='z' ) || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){

        T.push_back(s[i]);

            }

        }

        /*starting counter pointer i from index 0 and j from end  i.e n-1  */

        int i=0;

       

        int j= T.length()-1;

       /* here either i>=j or i<=j both are correct. */

        while(i<=j ){

         /* if char not equal not palindrome */

            if(Lower(T[i])!=Lower(T[j])){

                return false;

            }

      /* if equal increment i and decrement j and keep checking till i=j as that will be the stopping condition.  */    

            else{

                i++;

                j--;

            }

        } 

        /*finally coming out of while loop implies that it is palindrome.*/

       

        return true;

        

    }

};
