class Solution {

public:

    bool isAnagram(string s, string t) {

        

        int m = s.size();

        int n = t.size();

        

        if ( m!=n)

        { 

            return false ;

        }

        

  // 1st Method 

        /*

   sort(s.begin(), s.end());

sort(t.begin(), t.end());

        

        if(s==t){

            return true;

        }

        return false; */

        

        // 2nd Method 

        

         int arr[26] = {0} ;

        

   for (int i=0; i<s.size(); i++) {

    arr[s[i] - 'a']++;

     

   }

   

   for (int i=0; i< t.size(); i++) {

      if (arr[s[i]- 'a']<= 0) 

      { return false ;}

       arr[s[i]- 'a' ]-- ;

   }

         return true;

    }

};
