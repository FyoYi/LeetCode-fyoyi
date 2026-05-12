// 题目：https://leetcode.cn/problems/valid-parentheses

class Solution {
public:
  bool isValid(string s) {
    std::stack<char> n;
    for (auto i : s) {
      if (i == '(' || i == '[' || i == '{') {
        n.push(i);
      } else {
        if (n.empty())
          return false;

        if (i == ')' && n.top() != '(')
          return false;
        else if (i == ']' && n.top() != '[')
          return false;
        else if (i == '}' && n.top() != '{')
          return false;

        n.pop();
      }
    }
    return n.empty();
  }
};