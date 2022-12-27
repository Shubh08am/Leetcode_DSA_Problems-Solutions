class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        int n = a.size() , m = b.size();

        if(n!=m) return max(n,m);

        return n;
    }
};
