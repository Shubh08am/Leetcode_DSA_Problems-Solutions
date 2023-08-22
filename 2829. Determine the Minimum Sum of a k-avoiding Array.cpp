class Solution {
public:
    int minimumSum(int n, int k) {
        int res = 0 ; 
        set<int>s; 
        int no = 0 , currSum=0,val=1; 
        while(no<n){
            while(no<n && !s.count(k-val)){
                s.insert(val);
                currSum+=val;
                val++;
                no++;
            }
            val++;
        }
        return currSum;
    }
};
