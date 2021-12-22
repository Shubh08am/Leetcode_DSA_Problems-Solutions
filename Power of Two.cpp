Approach I :-
class Solution {

public:

    bool isPowerOfTwo(int n) {

        if ( n<= 0 )

            return false ;

        

        while ( n%2 == 0 )

        {    n = n/2 ;

        }

       return n == 1 ; 

    }

};

Approach II :-

Use for loop to scan and pow function and one variable to store answer and compare it with n if same return true otherwise return false.

