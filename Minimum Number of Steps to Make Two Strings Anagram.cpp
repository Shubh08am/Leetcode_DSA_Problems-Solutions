class Solution {
public:
    int minSteps(string s, string t) {
        
        //fixed sliding window pattern
        
        int i=0,j=0;
        int n = s.size() , diff=0;
        unordered_map<char,int>mp;
        
        //store frequency of all character present in s in map mp 
        for(auto&it:s) mp[it]++;
 
        while(j<n){
            // a-> 1 , b-> 2 in mp   --> s="bab" , t="aba"
            if(mp[t[j]]!=0){
                mp[t[j]]--; //decrement the frequency when that character of string t is present in mp// a->0 , b->1 --> a->0 , b->0
              //  if(mp[t[j]]==0) mp.erase(t[j]); //optional 
                j++;
            }
            
            else   {
                diff++; // when a found in t but not in map, diff++
                 j++;
            }
            
        }
        
         return diff ; 
    }
};
