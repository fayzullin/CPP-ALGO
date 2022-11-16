class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row_num = grid.size();
        col_num = grid[0].size();

        int islandsNum = 0;

        for (int i = 0; i < row_num; ++i) {
            for (int j = 0; j < col_num; ++j) {
                if (grid[i][j] == '0' || grid[i][j] == '2') continue;
                visitAllCellsOfIsland(grid, i, j);
                ++islandsNum;
            }
        }

        return islandsNum;
    }

private:
    void visitAllCellsOfIsland(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= row_num || col < 0 || col >= col_num) return;
        if (grid[row][col] == '0' || grid[row][col] == '2') return;

        grid[row][col] = '2';

        visitAllCellsOfIsland(grid, row, col - 1);
        visitAllCellsOfIsland(grid, row, col + 1);
        visitAllCellsOfIsland(grid, row - 1, col);
        visitAllCellsOfIsland(grid, row + 1, col);
    }

private:
    int row_num;
    int col_num;
};
