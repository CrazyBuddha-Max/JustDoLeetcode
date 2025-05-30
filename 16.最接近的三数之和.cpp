/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int r = n - 1, l = i + 1;
            while (r > l)
            {
                int sum = nums[i] + nums[r] + nums[l];
                if (abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
                if (sum == target)
                {
                    return target;
                }
                else sum > target ? r-- : l++;
            }
        }
        return ans;
    }
};
// @lc code=end
