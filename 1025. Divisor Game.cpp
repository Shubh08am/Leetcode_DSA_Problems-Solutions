class Solution {
public:
    bool divisorGame(int n) { 
        //Alice win only if n is even 
         return !(n&1);
    }
};
