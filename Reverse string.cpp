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
