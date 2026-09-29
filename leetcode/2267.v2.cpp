class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& dp, int i, int j,
             int nopen, int nclose) {
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
            if (dp[i][j + 1] && nopen == nclose)
                right = true;
            else
                right = dfs(grid, dp, i, j + 1, nopen, nclose);
        }
        if (!right && i < grid.size() - 1) {
            if (dp[i + 1][j] && nopen == nclose)
                down = true;
            down = dfs(grid, dp, i + 1, j, nopen, nclose);
        }

        if (right || down) {
            if (nopen == nclose)
                dp[i][j] = true;
            return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        vector<vector<bool>> dp(grid.size(),
                               vector<bool>(grid[0].size(), false));
        return dfs(grid, dp, 0, 0, 0, 0);
    }
};