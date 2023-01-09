class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
 long long int res = left;
 for(long long int i=left;i<=right;i++){
   res=res&i;
     if(res==0) {break;}
     }
     return res;       
    }
};
