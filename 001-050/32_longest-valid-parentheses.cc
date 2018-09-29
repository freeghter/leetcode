//
// Created by ft on 2018/9/29.
//
/**
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 * 示例 2:
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;

        int max = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == '(')
                continue;

            if(s[i-1] == '(')
                dp[i] = i-2 >= 0 ? dp[i-2]+2 : 2;
            else{
                if(i-dp[i-1] - 1 >= 0 && s[i-dp[i-1] - 1] == '('){
                    if(i-dp[i-1]-2 > 0)
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    else
                        dp[i] = dp[i-1] + 2;
                }
            }
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
};

int main(int argc, char * argv[]){
    Solution s;

    int max = s.longestValidParentheses("()()(()()())");
    cout << max;
    return 0;
}