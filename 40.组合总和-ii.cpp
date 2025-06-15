/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(const vector<int> &candidates, int target, int start_index)
    {
        if (target == 0)
        {
            result.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            if (i > start_index && candidates[i - 1] == candidates[i])
            {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return result;
    }
};
// @lc code=end
