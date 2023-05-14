class Solution {
public:
    int countVowelStrings(int n) {
        //for a -> e i o u  , e -> i o u , i-> o u , o->u
        // repeat as well character 
/*        int a,e,i,o,u,x=1,total=0;
        a=e=i=o=u=1;
        while(x<n){
           a=a+e+i+o+u; //for a
           e=e+i+o+u;  //for e
           i=i+o+u;  //for i
           o=o+u;  //for o
            x++; //for u
        }
        total=a+e+i+o+u;
        return total;
*/
        int total2 = (n+4)*(n+3)*(n+2)*(n+1)/24;
        return total2;
    }
};
