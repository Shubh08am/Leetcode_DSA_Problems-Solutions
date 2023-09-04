class Solution {
public:
    bool ok(int n){
        string s = to_string(n) ; 
        int m = s.size() , f=0; 
        if(m&1) return 0; 
        
        for(int i=0;i<m/2;i++){
            f+=(s[i]-'0');
        }
        
        for(int i=m/2;i<m;i++){
            f-=(s[i]-'0');
        }
        
        return f==0;
    }
    int countSymmetricIntegers(int low, int high) {
        int a=0;
        for(int i=low;i<=high;i++){
            a+=ok(i);
           // if(ok(i)) cout<<i<<" ";
        }
      return a;
    }
};
