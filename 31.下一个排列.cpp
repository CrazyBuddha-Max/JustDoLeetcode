/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int min = INT_MAX;
        int min_i = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                for (int j = n - 1; j >= 1; j--)
                {
                    if (nums[n - 1] > nums[i - 1])
                    {
                        int temp = nums[n - 1];
                        nums[n - 1] = nums[i - 1];
                        nums[i - 1] = temp;
                        break;
                    }

                    if (j == i)
                    {
                        int temp = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = temp;
                        break;
                    }
                    if (nums[j] > nums[i - 1] && nums[j + 1] < nums[i])
                    {
                        int temp = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = temp;
                        break;
                    }
                }
                for (int j = i; j < i + (n - i) / 2; j++)
                {
                    int temp = nums[j];
                    nums[j] = nums[n + i - j - 1];
                    nums[n + i - j - 1] = temp;
                }
                return;
            }
            else
            {
                if (nums[i] < min)
                {
                    min_i = i;
                    min = nums[i];
                }
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[n - 1 - i];
            nums[n - 1 - i] = temp;
        }
    }
};
// @lc code=end
