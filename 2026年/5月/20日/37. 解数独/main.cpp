// https://leetcode.cn/problems/sudoku-solver

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { BackTry(board, 0); }

  bool isTrue(size_t x, size_t y, char target, vector<vector<char>> &board) {
    for (int i = 0, j = 0; i < 9 && j < 9; ++i, ++j) {
      if (board[i][x] == target || board[y][j] == target)
        return false;
    }
    size_t xx = (x / 3) * 3;
    size_t yy = (y / 3) * 3;
    for (int i = yy; i < yy + 3; ++i) {
      for (int j = xx; j < xx + 3; ++j) {
        if (board[i][j] == target)
          return false;
      }
    }
    return true;
  }

  bool BackTry(vector<vector<char>> &board, size_t start) {
    if (start == 81)
      return true;
    for (int i = start; i < 81; ++i) {
      size_t x = i % 9;
      size_t y = i / 9;

      if (board[y][x] != '.')
        continue;

      for (char target = '1'; target <= '9'; ++target) {
        if (!isTrue(x, y, target, board))
          continue;

        board[y][x] = target;
        if (BackTry(board, i + 1))
          return true;
        board[y][x] = '.';
      }
      return false;
    }
    return true;
  }
};