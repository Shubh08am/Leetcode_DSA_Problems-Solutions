class Solution {

public:

    string reverseWords(string s) {

    stack<char>st ; 

        string b="";

        for(int i=0 ; i<s.size();i++){

            if(s[i]!=' ')

                {

                

               st.push(s[i]) ; 

                }

       else if(s[i]==' '){

           

          while(!st.empty()){

              

            b.push_back(st.top());

              st.pop();

              }

           } 

          if(st.empty())

              {b.push_back(' ');}

           } 

        

        while(!st.empty()){

           b.push_back(st.top());

            st.pop();

            }

            return b;

    }

};

        
