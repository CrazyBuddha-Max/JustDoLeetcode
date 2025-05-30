/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int maxArea = 0;
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            /* code */
            int area = (right - left) * min(height[left],height[right]);
            maxArea = max(maxArea,area);
            if (height[left] < height[right])
            {
                /* code */
                left += 1;
            }else{
                right -= 1;
            }
            
        }
        return maxArea;

    }
};
// @lc code=end
