/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0) ) return false;
        int revertedNumber = 0;
        while(x > revertedNumber){
            //前半部分是进位，后半部分取原数的末位数
            revertedNumber = revertedNumber *10 + x % 10;
            x /= 10;
        }
        return revertedNumber == x || x == revertedNumber/10;
    }
};
// @lc code=end

