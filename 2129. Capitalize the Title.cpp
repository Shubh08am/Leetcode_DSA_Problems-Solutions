class Solution {
public:
    string capitalizeTitle(string title) {
        title = " " + title;
        int n = title.size(), cnt = 0;
        string s(n, 'a');
        for(int i=n-1; i >= 0; i--) {
            if(title[i] == ' ')  {
                s[i] = ' ';
                if(cnt > 2) {
                    s[i+1] = toupper(title[i+1]);
                    }
                cnt = 0;
            }
            else {
                s[i] = tolower(title[i]);
                 cnt++;  
                 }  
        }
        s.erase(s.begin());
        return s;
    }
};
