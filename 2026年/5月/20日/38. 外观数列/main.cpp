// https: // leetcode.cn/problems/count-and-say

class Solution {
public:
  string countAndSay(int n) {
    std::string output = "1";
    for (size_t i = 1; i < n; ++i) {
      std::string input;
      size_t size = output.size();
      size_t left = 0, right = 0;
      std::cout << "output: " << output << endl;
      while (left < size) {
        right = left;
        while (right < size && output.at(right) == output.at(left)) {
          right++;
        }
        char num = '0' + (right - left);
        input.push_back(num);
        input.push_back(output.at(left));
        left = right;
      }
      output = input;
    }
    std::cout << "output: " << output << endl;
    return output;
  }
};