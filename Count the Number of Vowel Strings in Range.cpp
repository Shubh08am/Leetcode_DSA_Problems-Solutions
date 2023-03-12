class Solution {
public:
     bool is(char ch){
         return (ch=='a' || ch=='e' || ch=='i' ||  ch=='o' || ch=='u' );
     }
    int vowelStrings(vector<string>& words, int left, int right) {
        int a=0;
        for(int i=left;i<=right;i++){
            if(is(words[i][0]) && is(words[i].back())) a+=1;
        }
               return a;
    }
};
