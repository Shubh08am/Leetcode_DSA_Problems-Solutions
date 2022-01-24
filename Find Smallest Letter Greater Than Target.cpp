class Solution {

public:

    char nextGreatestLetter(vector<char>& letters, char target) {

       

        for(int i=0;i<letters.size();i++){

            if(letters[i]> target){

                 return letters[i];

            }

        } 

        // for z example

        if(letters[0]<target){

            return letters[0];

        }

        return ' ';

    }

};
