class Solution {
public:
    int minTimeToType(string word) {
int res = min(word[0] - 'a'+1 , 26 - (word[0] - 'a') +1);
   
     for (int i = 1; i < word.size(); ++i){
        res += min(abs(word[i] - word[i - 1])+1, 26 - abs(word[i] - word[i - 1])+1);
        }
        
    return res ;      
    }
};
