class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>freq;
        map<string,bool>vis;
        int equalWord = 0;
        int largestPalindromeLength = 0;
        int flg = 0 , mx=0;
        for(auto it : words){
            freq[it]++;
        }
       

        for(int i=0;i<words.size();i++){
        //see for curr_word and reverse_word in freq if exist , if both curr_word and reverse_word are equal take them only 1 time
        string curr_word = words[i];
        string reverse_word = curr_word ;
         reverse(reverse_word.begin(),reverse_word.end());

         // equal case take if even freq or if odd take only 1 time
         if(curr_word == reverse_word and vis[curr_word]==0 ){
            
             if( !(freq[curr_word]&1) ){
              largestPalindromeLength+= 2*freq[curr_word] ;
              vis[curr_word]=1 ;
             }
              
              //execute by decrementing 1 count
              else if ( (freq[curr_word]&1) ){
                  flg+=1;
                  largestPalindromeLength+= 2*(freq[curr_word]-1)  ;
                  vis[curr_word]=1 ;
              }
         }

//lclc llll clcl
        if(vis[curr_word]==0 and vis[reverse_word]==0){
        //find reverse in freq
        if(freq[reverse_word] > 0 and curr_word != reverse_word ){
            //take min occurence of curr_word and reverse_word
            largestPalindromeLength+= 4*min(freq[curr_word] , freq[reverse_word]);
            vis[curr_word]=1 ; 
            vis[reverse_word]=1;
        }
        }

        }
//if odd length was true take 1 more count
 if(flg) {
     largestPalindromeLength+= 2;
 }

        return largestPalindromeLength;
    }
};
