class Solution {
public:
    int countTime(string time) {
        int p = 1;
        if(time[4] == '?') p= p*10;
        if(time[3] == '?') p= p*6;
        
        if(time[1] == '?' && time[0] == '?'){
           p= p*24;
        }
        else if(time[0] == '?'){
            if(time[1]>='4'){
               p*= 2;
            }
            else {
            	p*= 3;
            }
        }
        
        else if(time[1] == '?'){
            if(time[0] == '2') {
            	p *= 4;
            }
            else {
            	p*= 10;
            }
        }
        
        return p;        
    }
};
