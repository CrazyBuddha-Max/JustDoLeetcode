/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int first = 0; first < n; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            // 双指针 nums[i] + nums[j] = -nums[k]

            int third = n - 1;
            int target = -nums[first];
            for (int secord = first + 1;secord < n; ++secord)
            {
                if (secord > first +1 && nums[secord] == nums[secord -1])
                {
                    continue;
                }
                
                while (secord < third && nums[secord] + nums[third] > target){
                    --third;
                }
                if (secord == third)
                {
                    break;
                }
                if (nums[secord] + nums[third] == target)
                { 
                    ans.push_back({nums[first],nums[secord],nums[third]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
