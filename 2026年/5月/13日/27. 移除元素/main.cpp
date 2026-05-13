// 题目：https://leetcode.cn/problems/remove-element/

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      while ((i < size) && (nums.at(i) == val)) {
        nums.erase(nums.begin() + i);
        size--;
      }
    }
    return size;
  }
};