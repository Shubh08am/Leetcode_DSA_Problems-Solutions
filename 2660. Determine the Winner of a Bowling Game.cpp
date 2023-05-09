class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int a=0,b=0,c=-1,d=-1;
        int n=p1.size(); 
         for(int i=0;i<n;i++){
             //prev 2 
            if(i>0 && p1[i-1]==10 or (i>1&&p1[i-2]==10)){
                a+=(p1[i]<<1);
            }
                else{
                    a+=p1[i];
                }
            }
            
            
         
        for(int i=0;i<n;i++){
             //prev 2 
            if(i>0 && p2[i-1]==10 or (i>1&&p2[i-2]==10)){
                b+=(p2[i]<<1);
            }
                else{
                    b+=p2[i];
                }
            }
            
            
        //   cout<<a<<" "<<b<<"\n" ; 
            if(a>b) return 1;
            if(a<b) return 2;
            return 0;
    }
};
