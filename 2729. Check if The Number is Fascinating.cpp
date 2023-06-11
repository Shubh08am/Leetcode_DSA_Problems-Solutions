class Solution {
public:
    bool isFascinating(int n) {
        int a = 2*n , b=3*n; 
        string s = to_string(n) +  to_string(a) +  to_string(b) ;
        vector<int>v(10,0) ; 
        for(auto x : s) v[x-'0']++; 
        
        for(int i=0;i<10;i++){
            if(i==0 && v[i]>0) return 0;
            if(i>0 && (v[i]==0 || v[i]>1) )return 0;
        }
        return 1;
    }
};
