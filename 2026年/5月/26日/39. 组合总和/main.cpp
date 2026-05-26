// https: // leetcode.cn/problems/combination-sum
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> output;
    vector<int> path;

    backtrack(candidates, target, 0, 0, path, output);

    return output;
  }

  void backtrack(vector<int> &candidates, int target, int start, int sum,
                 vector<int> &path, vector<vector<int>> &output) {

    if (sum == target) {
      output.push_back(path);
    }
    for (int i = start; i < candidates.size(); i++) {
      if (sum + candidates.at(i) > target)
        break;
      path.push_back(candidates.at(i));
      backtrack(candidates, target, i, sum + candidates.at(i), path, output);
      path.pop_back();
    }
  }
};