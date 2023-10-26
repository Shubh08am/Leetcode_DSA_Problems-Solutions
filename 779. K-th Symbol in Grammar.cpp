class Solution {
public:
    /*
    n=1 0  -> len = 2^(1-1)
    n=2 01  -> len = 2^(2-1)
    n=3 0110 -> len = 2^(3-1)
    n=4 01101001 -> len = 2^(4-1)

    prev_row+flip prev_row
    i.e divide in two part one before mid portion and one after mid portion 
    use prev_row for answering 
    */
    int solve(int n,int k){
        if(n==1 && k==1) return 0; 
        int len = (1<<(n-1)); 
        int mid = (len>>1); 
        //prev_row portion
        if(k<=mid){
            return solve(n-1,k);
        }
        //flip prev_row portion
        else{
             return 1-solve(n-1,k-mid); //subtract 1 for flipping or use not and go to first half of prev_row in term of k i.e k-mid
        }
    }
    int kthGrammar(int n, int k) {
        int bit=k-1,set=0; 
        while(bit) {set+=bit&1; bit>>=1;}
      //  return set&1?1:0;
        return solve(n,k);
    }
};
