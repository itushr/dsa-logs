class Solution {
public:
    bool dfs(vector<vector<char>> &grid, int i, int j, int nopen, int nclose) {
        if(grid[i][j] == '(') nopen++;
        else nclose++;

        if(nclose > nopen) return false;

        if(i == grid.size()-1 && j == grid[0].size()-1) {
            if(nopen == nclose) return true;
            return false;
        }

        bool right = false;
        bool down = false;

        if(j<grid[0].size()-1) right = dfs(grid, i, j+1, nopen, nclose);
        if(!right && i<grid.size()-1) down = dfs(grid, i+1, j, nopen, nclose);

        return right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        return dfs(grid, 0, 0, 0, 0);
    }
};