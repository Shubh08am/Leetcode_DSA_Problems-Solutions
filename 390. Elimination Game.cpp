class Solution {
public:
    int solve(int n){
        if(n==1) return 1;
        return 2*(n/2-solve(n/2)+1);
    }
    int lastRemaining(int n) {
       /* OBSERVATIONS:-
       [1] IF EVEN ALWAYS ALL ODD NUMBER REMOVED -> ANSWER = EVEN NO. 
       [2] IF ODD :- ALWAYS EVEN NUMBER ANSWER AS ODD REMOVED IN FIRST STEP ONLY
        
        EDGE CASE :- FOR N=1 -> ANSWER = 1 
        NOW,FOR ODD -> SUBCASES:- 
        IF NO. OF EVEN ELEMENT TILL N  ARE ODD -> ANSWER=0
        7 -> 4 
        5 -> 2
        11-> 8 
        13 -> 6 
        15 -> 8 
       */
  
     return solve(n);
     }
};
