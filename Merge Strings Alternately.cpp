class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i = 0, j = 0;
        string s ="" ;
        int r = max(a.size() , b.size()) ;
        while (i < r)
        {
            if (i < a.size()) s.push_back(a[i]);
            if (j < b.size()) s.push_back(b[j]);
            i++;j++;
        }
        
        return s;

    }
};
