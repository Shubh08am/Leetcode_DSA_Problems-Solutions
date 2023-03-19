class Solution {
    int n, m; // dimensions of the given grid.
    const int dx[4] = {-1,0,1,0}; // direction vector of x-axis.
    const int dy[4] = {0,1,0,-1}; // direction vector of y-axis.
public:
    // Function to check if the current cell (x,y) is a valid cell or not.
    // A valid cell must lie on or inside the boundary of the grid.
    int isValid (int x, int y) {
        if (x < n and x >= 0 and y < m and y >= 0) return 1; // if the cell is valid, then return true.
        return 0; // otherwise return false.
    }

    // DFS algorithm implementation to detect cycle in 2D - Grid. 
    int dfs (int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vis, int px, int py) {
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            // checking if the next cell is valid or not.
            if (isValid(nx, ny) == 1 and grid[nx][ny] == grid[x][y] and !(px == nx and py == ny)) {
                if (vis[nx][ny] == 1) return 1;
                else {
                    bool ok = dfs (nx, ny, grid, vis, x, y); // recursively calling dfs on unvisited cells.
                    if (ok == 1) return 1;
                }
            }
        }
        return 0;
    }

     bool containsCycle (vector<vector<char>>& grid) {
        n = grid.size(); // # of rows.
        m = grid[0].size(); // # of columns.
        vector<vector<int>> vis(n, vector<int>(m, 0)); // 2D visited array.
        int ok = 0;

        for (int i = 0; i < n; i++) {
            if (ok == 1) break;
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0) ok = dfs (i, j, grid, vis, -1, -1); // recursively calling for DFS to all the cells in the grid.
                if (ok) break; // if cycle is found, break out of recursion.
            }
        }
        return ok ? true : false; // return true if cycle exist otherwise false.
    }
};
