class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0,n=colors.size();
        for(int i=1;i<n-1;i++){
            alice+=(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A') ;
            bob+=(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B') ;
        }
    return alice>bob;
    }
};
