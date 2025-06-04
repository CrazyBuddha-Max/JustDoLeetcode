/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n =nums.size();
        int fast = 0,slow = 0;
        
        while (fast < n)
        {
            if (nums[fast] !=val)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
        
    }
};
// @lc code=end

