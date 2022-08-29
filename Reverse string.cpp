Approach I :- 

class Solution {

public:

    void reverseString(vector<char>& s) {



int start_index = 0 ;

        int end_index = s.size()-1 ;

        

        while (start_index < end_index)

        {

            swap(s[start_index++] , s[end_index--]);

        }

    }

};

Approach II :-
    
class Solution {

    public:

        void reverseString(vector<char>& s) {

        int i = 0;

        int j = s.size() -1;

        for(int x = 0; x<s.size()/2; x++){

            char temp = s[i];

            s[i] = s[j];

            s[j] = temp;

            i++;

            j--;

    

    }

    }

};

Approach III :-
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>stk;
        for(int u= 0 ; u<s.size();u++){
            stk.push(s[u]);
    }
       
      s.clear();
        
        while(!stk.empty()){
      
         s.push_back(stk.top()); 
        stk.pop();}
        } 
};
