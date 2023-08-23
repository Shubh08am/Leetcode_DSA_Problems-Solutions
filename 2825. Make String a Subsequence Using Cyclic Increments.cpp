class Solution {
public:
    bool diff(char ch1,char ch2){
        if(ch1=='z' && ch2=='a') return 1;
        return ch1-ch2==-1 ;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int n =  str1.size() , m = str2.size() ; 
        bool ok = 0 , flg = 0 ; 
        if(n<m) return 0;
        int i=0,j=0; 
        while(i<n && j<m){
            if(str1[i]==str2[j]){
                i++;
                j++;
            }
            else{
                if(diff(str1[i],str2[j]) == 0){
                    i++;
                }
                else{
                    while(diff(str1[i],str2[j])){
                        i++;
                        j++;
                    }
                }
            }
        }
        return j==m ; 
    }
};
