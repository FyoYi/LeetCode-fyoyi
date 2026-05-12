// 题目：https://leetcode.cn/problems/generate-parentheses

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    std::vector<string> output;
    std::string path;

    backtrack(n, 0, 0, path, output);

    return output;
  }

  void backtrack(int n, int left, int right, std::string &path,
                 std::vector<string> &output) {
    if (path.size() == 2 * n) {
      output.push_back(path);
      return;
    }

    if (left < n) {
      path.push_back('(');
      backtrack(n, left + 1, right, path, output);
      path.pop_back();
    }

    if (right < left) {
      path.push_back(')');
      backtrack(n, left, right + 1, path, output);
      path.pop_back();
    }
  }
};