class Solution {

public:

    string minRemoveToMakeValid(string s) {

        int n = s.size();   

        stack<int> st;

        string ans = "";

        for (int i = 0; i < n; ++i){       

            if (s[i] == '(')

                st.push(i);

            else if (s[i] == ')')

            {

                if (st.empty())

                    s[i] = '*';

                else

                    st.pop();

            }

        }

        while (!st.empty())

        {

            s[st.top()] = '*';

            st.pop();

        }

        // in resultant string(ans) exclude *

        for (int i = 0; i <n; ++i)

        {

            if (s[i] != '*')

                ans.push_back(s[i]);

        }

        return ans;

        

    }

};
