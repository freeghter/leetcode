//
// Created by ft on 2018/9/2.
//
/**
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
 *
 * 示例1:
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "abc"，其长度为 3。
 *
 * 示例2:
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 无重复字符的最长子串是 "b"，其长度为 1。
 *
 * 示例 3:
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "wke"，其长度为 3。
 * 请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty())
            return 0;
        int max = 1;
        vector<int> dp(s.size(), 1);
        for (int i = 1; i < s.size(); ++i) {
            int n = 1;
            for (; n <= dp[i-1]; ++n) {
                if(s[i] == s[i - n])
                    break;
            }
            dp[i] = n;
            if(n > max)
                max = n;
        }
        return max;
    }
};

int main(int argc, char * argv[]){
    Solution s;
    int r = s.lengthOfLongestSubstring("abcabcbb");
    cout << r << endl;

    r = s.lengthOfLongestSubstring("bbbbb");
    cout << r << endl;

    r = s.lengthOfLongestSubstring("pwwkew");
    cout << r << endl;
    return 0;
}