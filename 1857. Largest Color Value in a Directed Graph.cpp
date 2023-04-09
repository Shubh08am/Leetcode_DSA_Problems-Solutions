class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegrees(n, 0);
        vector<int>adj[n];

        for (auto&it : edges) {
            adj[it[0]].push_back(it[1]); // it[0] -> it[1] [directed edges]
            indegrees[it[1]]++;
        }

        queue<int>q ;

        //push all nodes in queue whose indegree are zero
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>>freq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            freq[i][colors[i] - 'a']++;
        }
        int color = 0;
        int visited = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;

            for (auto&v : adj[u]) {
                //atmost 26 character
                for (int i = 0; i < 26; i++) {
                    freq[v][i] = max(freq[v][i], freq[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                //remove the edge between u&v
                indegrees[v]--;
                //if indegree becomes 0 insert in queue v
                if (indegrees[v] == 0) {
                    q.push(v);
                }
            }
            //track color 
            color = max(color, *max_element(freq[u].begin(), freq[u].end()));
        }
        return visited == n ? color : -1;
    }
};
