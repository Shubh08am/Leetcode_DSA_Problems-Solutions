class Solution {
public:
int reverse(int n){
    int rev=0;
    while(n){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=1e5;i++){
          int reverse_no = reverse(i);
          if(reverse_no+i==num){
              return 1;
          }
        }
        return 0;
    }
};
