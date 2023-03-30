class Solution {
public:    
    unordered_map<string,bool> dp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();

        if(s1==s2) return true;   
        if(n==1) return false; //i.e s1!=s2
        
        string scramble = s1+" "+s2; // (" " to differntiate)
        
        if(dp.count(scramble)) return dp[scramble];

        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n),s2.substr(i,n))){
                return dp[scramble] = true;
            }
            
            if(isScramble(s1.substr(0,i),s2.substr(n-i,n)) && isScramble(s1.substr(i,n),s2.substr(0,n-i))){
                return dp[scramble] = true;
            }
        }
        return dp[scramble] = false;
    }
};
