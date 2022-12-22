class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto&i:s) mp[i]++;

        int evenLen=0, longestPalindrome=0 , oddLen=0;
        bool visited=0;
        for(auto&it:mp){
            int freq = it.second ;
        
        //take all freq if even number of times
                if(!(freq&1)){
                    evenLen+=freq;
                }
                else if(freq&1){
     //a->3,b->5,c->7 --> take c (7) all and rest freq-1 times i.e a->2 and b->4 , take max one time and left one freq-1 times
                    visited=1;
                   oddLen+=freq-1; 
                }
        }

       longestPalindrome = evenLen;

        if(visited){
     longestPalindrome+=oddLen+1; //+1 bcs max freq was taken freq-1 times above so make it freq times
        }

return longestPalindrome;

    }
};
