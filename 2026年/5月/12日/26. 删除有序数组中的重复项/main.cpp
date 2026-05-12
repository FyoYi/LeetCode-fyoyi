// 题目：https://leetcode.cn/problems/remove-duplicates-from-sorted-array

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {

    int size = nums.size();
    if (size == 0)
      return 0;
    for (int i = 1; i < size; i++) {
      while ((i < size) && (nums.at(i) == nums.at(i - 1))) {
        nums.erase(nums.begin() + i);
        size--;
      }
    }
    return size;
  }
};