class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int>s; 
        map<int,int>r;
        for(auto i:ranks) r[i]++;
         for(auto i:suits) s[i]++;
       
        for(auto it:s) {
            if(it.second==5) return "Flush";
        }
         for(auto it:r) {
            if(it.second>=3) return "Three of a Kind";
            
        }
         for(auto it:r) {
       if(it.second==2) return "Pair";
    }
        return "High Card";
    }
};
