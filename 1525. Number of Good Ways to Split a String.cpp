class Solution {
public:
    int numSplits(string s) {
    /*
    aacaba
    pre    1 1 2 2 3 3 
    suf    3 3 3 2 2 1

    abcd
    pre    1 2 3 4
    suf    4 3 2 1 

    split+=pre[i]=suf[i+1]?1:0
    */
    int n= s.size() , split=0 ; 
    vector<int>pre(n,0),suf(n,0);
    unordered_set<char>pre_unique,suf_unique;
    for(int i=0;i<n;i++){
        pre_unique.insert(s[i]) ; 
        pre[i]=pre_unique.size();

        suf_unique.insert(s[n-i-1]) ; 
        suf[n-i-1]=suf_unique.size();
    }
    
    for(int i=0;i<n-1;i++){
        split+=pre[i]==suf[i+1]?1:0;
    }
    return split;
    }
};
