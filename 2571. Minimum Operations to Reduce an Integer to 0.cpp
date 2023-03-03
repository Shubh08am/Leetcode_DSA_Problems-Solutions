class Solution {
public:
    int minOperations(int n) {
        //take lower bound and upperbound and than take min diff one 
        int diff1=0 , diff2=0, cnt=0 ;
        while(n){ 
        int lb = pow(2,(int)log2(n)) ;
        int ub = pow(2,(int)(log2(n)+1)) ;
        
            diff1 = abs(n-lb) ; 
            diff2 = abs(ub-n) ;
            //update n by min difference
            n = min(diff1 , diff2) ; 
          //  cout<<n<<" "<<lb<<" "<<ub<<"\n";
             cnt++; 
        }
        return cnt;
    }
};
