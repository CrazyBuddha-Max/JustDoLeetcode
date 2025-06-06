/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 非递减顺序意味着数组中的元素按照从小到大的顺序排列，但允许相邻的元素相等。
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans = {-1, -1};
        // 找到首位位置 找小的往左边二分
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                ans[0] = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        //没找到
        if (ans[0] == -1)
        {
            return ans;
        }

        //找到末尾位置 找大的往右边二分
        left = ans[0], right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                ans[1] = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end
