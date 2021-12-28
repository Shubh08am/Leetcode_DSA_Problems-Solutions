class Solution {

public:

    bool isValid(string s) {

       stack<char> t;

        

        for(int i=0;i<s.size();i++) {

        

              char top = t.empty() ? '#' : st.top();

            

            if(top == '(' && s[i] == ')') {

                t.pop();

            }

            

            else if(top == '{' && s[i] == '}') {

                t.pop();

            }

            else if(top == '[' && s[i] == ']') {

                t.pop();

            }

            

              else{

                t.push(s[i]);

            }    

        }

        

        return t.empty();

    }

};

    
// or not using ternary operators:-
    class Solution {

public:

    bool isValid(string s) {

       stack<char> t;

        

        for(int i=0;i<s.size();i++) {

        

         //     char top = t.empty() ? '#' : t.top();

      char top ;

            if ( t.empty() )

            {

                 top = '#' ;

            }

            else 

            {

                 top = t.top() ;

            }

                

            if(top == '(' && s[i] == ')') {

                t.pop();

            }

            

            else if(top == '{' && s[i] == '}') {

                t.pop();

            }

            else if(top == '[' && s[i] == ']') {

                t.pop();

            }

            

              else{

                t.push(s[i]);

            }    

        }

        

        return t.empty();

    }

};

•This passes 45/91 test cases , needs to also use erase or remove function of strings. 

class Solution {

public:

    bool isValid(string s) {

        

        int i ;

        //s = "(){}[]" ;

        

        for ( i = 0 ; i<s.size() ; i++) 

        {

            if ( s[i] == '(' && s[i+1] == ')' )

                return true ;

            

            else if ( s[i] == '{' && s[i+1] == '}' )

                return true ;

            

            else if ( s[i] == '[' && s[i+1] == ']' )

                return true ;

        }

        return false ;

    }

};
