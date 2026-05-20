// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    std::size_t size = nums.size();
    std::vector<int> output{-1, -1};
    int right = size - 1;
    int left = 0;
    if (size == 1) {
      if (nums.at(0) == target) {
        std::vector<int> out{0, 0};
        return out;
      } else
        return output;
    }
    if (size == 2) {
      if (nums.at(0) == target && nums.at(1) != target) {
        std::vector<int> out{0, 0};
        return out;
      } else if (nums.at(1) == target && nums.at(0) != target) {
        std::vector<int> out{1, 1};
        return out;
      } else if (nums.at(0) == target && nums.at(1) == target) {
        std::vector<int> out{0, 1};
        return out;
      } else
        return output;
    }

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid < 0)
        break;
      if (nums.at(mid) == target) {
        output.at(0) = mid;
        output.at(1) = mid;
        break;
      }
      if (nums.at(mid) > target)
        right = mid - 1;
      else if (nums.at(mid) < target)
        left = mid + 1;
    }
    while ((output.at(1) < size - 1) && (nums.at(output.at(1) + 1) == target))
      output.at(1)++;
    while ((output.at(0) > 0) && (nums.at(output.at(0) - 1) == target))
      output.at(0)--;
    return output;
  }
};