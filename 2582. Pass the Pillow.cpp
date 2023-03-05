class Solution {
public:
    int passThePillow(int n, int t) {
        int cp=1,dr=1,a=0; 
       for(int i=0;i<t;i++){
           if(cp==1) dr=1;
           else if(cp==n) dr=-1;
           cp+=dr;
       }
        return cp ; 
    }
};
