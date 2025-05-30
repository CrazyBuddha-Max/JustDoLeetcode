/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
    int result = 0;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        int currentValue = getValue(s[i]);
        if(i + 1 < n && currentValue < getValue(s[i + 1])){
            result -= currentValue;
        }else{
            result += currentValue;
        }
    }
    return result;

    }
private:
    int getValue(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
// @lc code=end

