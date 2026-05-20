// https://leetcode.cn/problems/valid-sudoku/

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[y][x] != '.') {
          int num = board[y][x] - '0';
          int box_num = (y / 3) * 3 + (x / 3);

          if (row[y][num] || col[x][num] || box[box_num][num])
            return false;
          row[y][num] = true;
          col[x][num] = true;
          box[box_num][num] = true;
        }
      }
    }
    return true;
  }
};