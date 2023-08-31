class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //same as jump game 2 
        int m = ranges.size() ; 
        vector<int>maxJumpFromHere(n+1,0) ; 
        for(int i=0;i<m;i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            maxJumpFromHere[start]=max( maxJumpFromHere[start],end);
        }

        int maxEnd = 0 , currEnd = 0 , taps = 0 ; 

        for(int i=0;i<m;i++){
            if(i>maxEnd){
                return -1;
            }
            if(i>currEnd){
                taps++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,maxJumpFromHere[i]);
        }
    return taps ; 
    }
};
