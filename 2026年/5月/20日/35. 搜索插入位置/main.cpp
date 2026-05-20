// https://leetcode.cn/problems/search-insert-position

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    std::size_t size = nums.size();
    int right = size - 1;
    int left = 0;
    int mid = 0;
    if (target < nums.at(0))
      return 0;
    if (target > nums.at(size - 1))
      return size;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (mid < 0)
        break;
      if (nums.at(mid) == target)
        return mid;

      if (nums.at(mid) > target)
        right = mid - 1;
      else if (nums.at(mid) < target)
        left = mid + 1;
    }
    return left;
  }
};