class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size() ; 
         map<char,int>o1,o2,e1,e2;
        
         for(int i=0;i<n;i++){
             if(i&1){
                 o1[s1[i]]++;
                 o2[s2[i]]++;
             }
             if(!(i&1)){
                 e1[s1[i]]++; 
                 e2[s2[i]]++;
             }
        }
        return o1==o2 && e1==e2;
    }
};
