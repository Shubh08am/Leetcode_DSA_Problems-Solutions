class Solution {
public:
    string addBinary(string a, string b) {
     
        int n = a.size();
        int m = b.size();
        string ans="";
        int i=n-1 , j=m-1 , carry=0;
        while(i>=0  || j>=0)
        {
            int sum=0;
            if(i>=0)
            {
                sum+=(a[i]-'0');
                
            }
            
            if (j>=0)
            {
                sum+=(b[j]-'0');
                
            }
            sum+=carry;
            int d = sum%2;
            carry = sum/2;
            char t = d + '0';
            ans=t+ans;
            
            if(i>=0)
                i--;
            if(j>=0)
                j--;
            
        }
        if(carry>0)
            ans= ('1') + ans;
        return ans;
        
    }
};
