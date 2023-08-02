class Solution {
public:
    int myAtoi(string s) {
        long long n = s.size() , i=0 , num=0; 
        if(n==0) return 0 ; 

        //LEADING SPACE 
        while(i<n && s[i]==' ') i++;

        bool pos = 1 , neg = 0 ; 

        if(s[i]=='-') neg = 1 ; 
        int maxi = INT_MAX , mini = INT_MIN; 

        //SKIP + && - 
        if(s[i]=='+' || s[i]=='-') i++;

        n = s.size() ; 
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i]-'0' ; 
            
                //MIN CASE 
                if(neg && mini > -num){
                    return mini;
                }

                //MAX CASE 
                if(pos && !neg && maxi < num){
                    return maxi;
                }
            }
            else break;
            i++;
        }
        
    return neg==1?-num:num;
    }
};
