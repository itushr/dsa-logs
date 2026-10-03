class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }

        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        q.push({-1, -1});

        int ans = 1;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if(i == -1) {
                ans++;
                if(!q.empty()) q.push({-1, -1});
                continue;
            }

            if(i == n-1 && j == m-1) {
                return ans;
            }

            // left
            if(j > 0 && !visited[i][j-1] && grid[i][j-1] == 0) {
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }

            // top
            if(i > 0 && !visited[i-1][j] && grid[i-1][j] == 0) {
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }

            // right
            if(j < m-1 && !visited[i][j+1] && grid[i][j+1] == 0) {
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }

            // bottom
            if(i < n-1 && !visited[i+1][j] && grid[i+1][j] == 0) {
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }

            // top-left
            if(i > 0 && j > 0 && !visited[i-1][j-1] && grid[i-1][j-1] == 0) {
                visited[i-1][j-1] = 1;
                q.push({i-1, j-1});
            }

            // top-right
            if(i > 0 && j < m-1 && !visited[i-1][j+1] && grid[i-1][j+1] == 0) {
                visited[i-1][j+1] = 1;
                q.push({i-1, j+1});
            }

            // bottom-left
            if(i < n-1 && j > 0 && !visited[i+1][j-1] && grid[i+1][j-1] == 0) {
                visited[i+1][j-1] = 1;
                q.push({i+1, j-1});
            }

            // bottom-right
            if(i < n-1 && j < m-1 && !visited[i+1][j+1] && grid[i+1][j+1] == 0) {
                visited[i+1][j+1] = 1;
                q.push({i+1, j+1});
            }
        }

        return -1;
    }
};