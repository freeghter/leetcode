//
// Created by ft on 2018/9/3.
//
/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
 *
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba"也是一个有效答案。
 *
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        string r = s.substr(0, 1);
        int pos = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
                if (r.size() < 2)
                    r = s.substr(i, 2);
            }
        }
        // 注意这里要通过对角线来计算
        for (int i = 2; i < s.size(); ++i) {
            for (int j = 0; j + i < s.size(); ++j) {
                unsigned int left = j, right = i+j;
                if(s[left]==s[right] && dp[left+1][right-1]){
                    dp[left][right] = dp[left+1][right-1] + 2;
                }
                if(dp[left][right] > r.size()){
                    r = s.substr(left, right-left+1);
                }
            }
        }
        return r;
    }
};

int main(int argc, char *argv[]) {

    Solution s;

    vector<string> ins = {"eabcb", "abcba", "babad", "cbbd"};
    for (string i: ins) {
        cout << i << " " << s.longestPalindrome(i) << endl;
    }
    return 0;
}