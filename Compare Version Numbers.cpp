class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s=0 ; 
        
        int sum = 0 ;
        int m =version1.size() ;
        int n= version2.size();
        
         int i = 0, j = 0; 
        while(i<m|| j<n)
        {
            while(i<m && version1[i]!='.')
            {
                s= s*10+(version1[i]-'0');
                i++;
            }
            while(j<n && version2[j]!='.')
            {
                sum = sum*10+(version2[j]-'0');
                j++;
            }
            if(s>sum)
            {
                return 1;
            }
            if(s < sum) 
            {
                return -1;
            }
            i++;
            j++;
            s = 0;
            sum = 0;
        }
        return 0; 
    }
};
