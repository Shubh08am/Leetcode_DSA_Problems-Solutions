class Solution {
public:
bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ) return 1;
     if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ) return 1;
     return 0;
}
    string reverseVowels(string s) {
        int n = s.size();
        int start=0,end=n-1;
        while(start<end){
        if(!isVowel(s[start])) start++;
        if(!isVowel(s[end])) end--;
       else if(!isVowel(s[end]) && isVowel(s[start]) ) end--;
       else if(isVowel(s[end]) && !isVowel(s[start]) ) start++;
        else{
            swap(s[start],s[end]);
            start++;
            end--;
        }

        }
        return s;
    }
};
