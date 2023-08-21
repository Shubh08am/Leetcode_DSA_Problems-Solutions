/*
Jaise maanlo 
abc abc abc abc hain 
12 Len kii string tho ab agr mein iss string ka At Max half part consider krskta hu 
Phir hii usko concatenate krke n ke equal bna skta i.e (n/2)*2 = n hoga 

Ab mein 0 se lekar n/2 tak traverse krunga ye check krne kya ye possible hain 

Ab mein haar baar kuch sub string bnakar usko kuch time concatenate krke check krunga given string se match krra kya 

Given string mein mein agr abc ko lelu aur usko 4 baar concatenate kru tho result miljayega tho ye hoga kaise :- 
Agr mein uss substring kii Len ko lera jiska n%Len = 0 hoo tabhi possible hain kyuki mein tabhi given substring ko n/(i+1) times concatenate krunga 
Tho aise hii jabhi i=0->n/2 mein n%(i+1) = 0 hoo tab tab mein 0 se lekar (i+1) tak kii substring ko n/(i+1) times concatenate krke check krlunga

Iska t.c = 2*sqrt(n)*n hojayega kyuki kisi bhi no ka at max 2*sqrt(n) divisor hota hain aur n substring ko concatenate krne ke liye at worst case
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size() ; 
        for(int i=0;i<n/2;i++){
            if(n%(i+1)==0){
                string p = s.substr(0,i+1);
                string temp=p;
                int concatenate=n/(i+1);
                while(--concatenate) p+=temp;
                if(p==s) return 1;
            }
        }
    return 0;
    }
};
