struct coords
{
    int row;
    int column;

    bool operator==(const coords& coords) const
    {
        return row == coords.row && column == coords.column;
    }

    friend ostream& operator<<(ostream& os, coords coords)
    {
        os << "(" << coords.row << ", " << coords.column << ")";
        return os;
    }
};

class Solution {
public:
    static void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (isCellEmpty(board, {i, j}))
                {
                    bool isSolved = solveSudokuImpl(board, {i, j});
                    if (!isSolved)
                    {
                        throw std::runtime_error("Your board has no solution");
                    }
                }
            }
        }
    }

private:
    static bool solveSudokuImpl(vector<vector<char>>& board, coords currEmptyCell)
    {
        if (currEmptyCell == coords{-1, -1})
        {
            return true;
        }

        for (char i = '1'; i <= '9'; ++i)
        {
            if (isNumInCurrRow(i, currEmptyCell, board)) continue;
            if (isNumInCurrColumn(i, currEmptyCell, board)) continue;
            if (isNumInCurrSubBox(i, currEmptyCell, board)) continue;

            board[currEmptyCell.row][currEmptyCell.column] = i;
            coords nextEmptyCell = getNextEmptyCell(board, currEmptyCell);

            bool isSolved = solveSudokuImpl(board, nextEmptyCell);
            if (isSolved)
            {
                return true;
            }
        }

        board[currEmptyCell.row][currEmptyCell.column] = '.';
        return false;
    }

    static bool isNumInCurrRow(char num, coords currCoords, const vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[currCoords.row][i] == num)
            {
                return true;
            }
        }
        return false;
    }

    static bool isNumInCurrColumn(char num, coords currCoords, const vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][currCoords.column] == num)
            {
                return true;
            }
        }
        return false;
    }

    static bool isNumInCurrSubBox(char num, coords currCoords, const vector<vector<char>>& board)
    {
        int subBoxRowInd = currCoords.row / 3;
        int subBoxColumnInd = currCoords.column / 3;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[subBoxRowInd * 3 + i][subBoxColumnInd * 3 + j] == num)
                {
                    return true;
                }
            }
        }
        return false;
    }

    static coords getNextEmptyCell(const vector<vector<char>>& board, coords currEmptyCell)
    {
        for (int i = currEmptyCell.row; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (isCellEmpty(board, {i, j}))
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    static bool isCellEmpty(const vector<vector<char>>& board, coords cell)
    {
        return board[cell.row][cell.column] == '.';
    }
};

void printBoard(const vector<vector<char>>& board)
{
    for (int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::cout << board[i][j] << "  ";
        }
        std::cout << "\n";
    }
};