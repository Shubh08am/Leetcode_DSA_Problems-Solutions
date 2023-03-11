class Solution {
public: 
   bool isdivisible(int n , int m){
       if(m==0) return 0;
        return n%m==0 ;
   }
    vector<int> selfDividingNumbers(int left, int right) {
         vector<int>ans;

        for(int i=left;i<=right;i++){
            int num = i , cnt=0,enter=0;
            while(num){
                if(isdivisible(i,num%10)) cnt++;
                num/=10;
                enter++;
            }
            if(cnt==enter) ans.push_back(i);
        }
         return ans;
    }
};
