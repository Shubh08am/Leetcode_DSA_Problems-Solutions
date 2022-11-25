class Solution {
public:
    int totalMoney(int n) {
        int d = 1,j=1 , ans= 0; bool f=0; 
       for(int i= 1;i<=n ; i++){
     if(i%7==1 and i!=1 ){ 
         ++d; f=1;
         j=d;
         } 
          else if(!f) j=i;
        else    if(f) ++j;
    ans+=j;
           } 
        return ans;
    }
};
