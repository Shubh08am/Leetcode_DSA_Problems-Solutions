class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size()+1 , m=searchWord.size(),word=0; 
        for(int i=0;i<n-m;i++){
            if(sentence[i]==' ' || i==0){
                word++;
                int pos =i==0?0:1;
                if(sentence.substr(i+pos,m)==searchWord) return word;
            }
        }
    return -1;
    }
};
