// https://leetcode.cn/problems/next-permutation

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    std::size_t size = nums.size();
    std::size_t point = size - 1;
    while ((point >= 1) && (nums.at(point) <= nums.at(point - 1))) {
      point--;
    }
    if (point > 0) {
      std::size_t f_min = nums.at(point - 1);
      std::size_t n = size - 1;
      while (nums.at(n) <= f_min)
        n--;
      nums.at(point - 1) = nums.at(n);
      nums.at(n) = f_min;
      reverse(nums.begin() + point, nums.end());
    } else {
      reverse(nums.begin(), nums.end());
    }
  }
};