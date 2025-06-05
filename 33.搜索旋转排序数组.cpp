/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right)
        {
            // 在计算中点时，直接使用 (left + right) / 2 可能会导致整数溢出，特别是当 left 和 right 都是很大的整数时。而 left + (right - left) / 2 可以避免这种情况，因为 right - left 通常是一个较小的数，不会导致溢出。
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                (target >= nums[left] && target < nums[mid]) ? right = mid - 1 : left = mid + 1;
            }
            else
            {
                (target <= nums[right] && target > nums[mid]) ? left = mid + 1 : right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
