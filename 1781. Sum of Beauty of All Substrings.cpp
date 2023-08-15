class Solution {
public:
    int beautySum(string s) {
        /*  s = "aabcb"
            aab 
            aabc 
            aabcb 
            abcb 
            bcb
        */
        int beauty = 0 , n = s.length(); 
        for(int i=0;i<n;i++){
            unordered_map<char,int>freq ; 
            for(int j=i;j<n;j++){
                int maxFreq =0 , minFreq = 501 ;
                freq[s[j]]++;
                for(auto&it:freq){
                    minFreq=min(minFreq,it.second);
                    maxFreq=max(maxFreq,it.second);
                }
                beauty+=(maxFreq-minFreq);
            }
        }
    return beauty;
    }
};
