class Solution {
public:
    int maxNumberOfBalloons(string text) {
      unordered_map<char,int>freq ; 
      for(auto&ch:text) freq[ch]++;

      int balloons=0;
      while(1){
          if(freq['b']==0 || freq['a']==0  || freq['l']<2   || freq['o']<2  || freq['n']==0 ) break;
          freq['b']--;freq['a']--;freq['l']-=2;freq['o']-=2;freq['n']--;
          balloons++;
      }
      return balloons;
    }
};
