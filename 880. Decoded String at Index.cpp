class Solution {
public:
   bool isdigit(char ch){
        int value = ch-'0';
        return value>0 && value<=9 ;
    }
    string decodeAtIndex(string s, int k) {
        long long totalLength = 0;
        // Compute total length
        for (auto ch : s) {
            if (isdigit(ch)) {
                totalLength *= (ch - '0');
            } 
            else {
                totalLength++;
            }
        }
       // cout << totalLength << "\n" ;
        // moving backward until having the letter at position k
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                totalLength /= (s[i] - '0'); 
                k = k % totalLength;
             //   cout << totalLength << " "<<k<<"\n" ;
            } 
            else {
                if (k == 0 || totalLength == k)  {
                    string ans = string(1,s[i]);
                    return ans;
                }
                //1 word reduced
                totalLength--; 
            }
        }
        return "";
    }
};
