class Solution {
public: 
    int recursion(int num , int &cnt){
          if(!num) return cnt;
          else if(num&1) return recursion(--num,++cnt);
          return recursion(num>>1,++cnt);
    }
    int numberOfSteps(int num) {
        int cnt=0;
        return recursion(num,cnt);
    }
};
