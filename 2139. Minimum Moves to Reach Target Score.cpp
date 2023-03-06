class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        if(!maxDoubles) return --target;
        while(target){
            if(target&1) target--;
            else if(maxDoubles){
            target>>=1;
            maxDoubles--;
            }
            else if(!maxDoubles){
             target--;
            }
            cnt++;
        }
        return cnt-1;
    }
};
