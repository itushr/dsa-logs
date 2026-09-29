class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<vector<int>>>& dp, int i,
             int j, int nopen, int nclose) {
        if (grid[i][j] == '(')
            nopen++;
        else
            nclose++;

        if (nclose > nopen)
            return false;

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (nopen == nclose)
                return true;
            return false;
        }

        bool right = false;
        bool down = false;

        if (j < grid[0].size() - 1) {
            if (dp[i][j + 1][nopen - nclose] != -1)
                right = dp[i][j + 1][nopen - nclose];
            else
                right = dfs(grid, dp, i, j + 1, nopen, nclose);
                dp[i][j+1][nopen-nclose] = right;
        }
        if (!right && i < grid.size() - 1) {
            if (dp[i + 1][j][nopen - nclose] != -1)
                down = dp[i + 1][j][nopen - nclose];
            else
                down = dfs(grid, dp, i + 1, j, nopen, nclose);
                dp[i+1][j][nopen-nclose] = down;
        }

        if(right || down) return true;
        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        vector<vector<vector<int>>> dp(
            grid.size(),
            vector<vector<int>>(
                grid[0].size(),
                vector<int>(grid.size() + grid[0].size() + 1, -1)));
        return dfs(grid, dp, 0, 0, 0, 0);
    }
};