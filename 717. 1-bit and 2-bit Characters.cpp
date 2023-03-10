class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int end = n ,start=0, one = 0 ; 
        for(int i=n-2;i>=0;--i) {
            if(bits[i]==0) {
                start=i;
                break;
            }
        } 
        one = count(bits.begin() + start , bits.begin()+end,1) ; 
        return (one&1)==0; 
     }
};
