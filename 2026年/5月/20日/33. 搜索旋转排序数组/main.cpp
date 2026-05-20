// https://leetcode.cn/problems/search-in-rotated-sorted-array

class Solution {
public:
  int search(vector<int> &nums, int target) {
    std::size_t size = nums.size();
    std::size_t point;
    int left = 0;
    int right = nums.size() - 1;
    if (size == 1) {
      return nums.at(0) == target ? 0 : -1;
    }
    if (size == 2) {
      if (nums.at(0) == target)
        return 0;
      else if (nums.at(1) == target)
        return 1;
      else
        return -1;
    }
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums.at(mid) == target)
        return mid;

      if (nums.at(left) <= nums.at(mid)) {
        if (target >= nums.at(left) && target < nums.at(mid))
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if (target > nums.at(mid) && target <= nums.at(right))
          left = mid + 1;
        else
          right = mid - 1;
      }
    }

    return -1;
  }
};