// https://leetcode.cn/problems/combination-sum-ii/
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> output;
    vector<int> path;

    backtrack(candidates, output, path, target, 0, 0);

    return output;
  }

  void backtrack(vector<int> &candidates, vector<vector<int>> &output,
                 vector<int> &path, int &target, int start, int sum) {
    if (sum == target) {
      output.push_back(path);
    }
    for (int i = start; i < candidates.size(); i++) {
      if (sum + candidates.at(i) > target)
        break;
      if (i > start && candidates.at(i) == candidates.at(i - 1))
        continue;
      path.push_back(candidates.at(i));
      backtrack(candidates, output, path, target, i + 1,
                sum + candidates.at(i));
      path.pop_back();
    }
  }
};