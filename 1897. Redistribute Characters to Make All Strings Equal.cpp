class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size() ; 
        string s="" ; 
        for(int i=0;i<n;i++){
                s+=words[i];
        }
        for(char ch='a' ; ch<='z' ; ch++){
            int cnt = count(s.begin(),s.end(),ch) ; 
            if(cnt%n!=0) return false;
        }
        return true;
    }
};
