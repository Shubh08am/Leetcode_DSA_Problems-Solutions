class Solution {
public:
    int minimumSum(int num) {
        
        int v[4];
    int j,i = 0 , r;
int ans=0;
        
    while (num != 0) {
  
        r = num % 10;
  
        v[i] = r;
        i++;
  
        num = num / 10;
    }
         sort(v , v+4);
        
        if(v[0]==0 && v[1]==0)
        {int s =  v[2] + v[3];
        return s ;
        }
       
       else if (v[0]==0)
        {
            int o = v[1]*10 + v[2];
            
         return v[3] + o;
        } 
        
            else if (v[0]==0 && v[1]==0 && v[2]==0)
        return v[3];
        
        else{ 
            //sort(v , v+4);
            
            int s = v[0]*10 + v[1];
            int p = v[2]*10 + v[3];
            int q = s+p;
            
            int e = v[0]*10 + v[2];
            int t = v[1]*10 + v[3];
            int n = e+t;
            
            int d = v[0]*10 + v[3];
            int k = v[1]*10 + v[2];
            int m = d+k;
            
            int ans = min({m,n,q});
          
            return ans;
        }
       
        return -1 ;
    }
};
