class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<1)return false;
     else{   double k = log10(n)/(log10(3)*1.0);
 //cout<<floor(k)  << " "<<ceil(k)<<endl; 
        int ce = ceil(k/1.0); int fl = floor(k);
        if(ce ==fl){
            return true;
        }}
        return false;
    }
};
