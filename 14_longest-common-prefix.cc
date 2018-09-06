//
// Created by ft on 2018/9/6.
//
/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 * 示例 2:
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 * 说明:
 * 所有输入只包含小写字母 a-z 。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r;

        if(strs.empty())
            return r;

        bool flag = true;
        for (int i = 0; i < strs[0].size() && flag; ++i) {
            char c = strs[0][i];
            for (auto s: strs){
                if(s.size() <= i || c != s[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                r += c;
        }
        return r;
    }
};

int main(int argc, char * argv[]){
    vector<pair<vector<string>, string>> test_cases{
            {{"abca","abc"}, "abc"},
            {{"abb","abc"}, "ab"},
            {{"flower","flow","flight"}, "fl"},
            {{"dog","racecar","car"}, ""},
            {{},""},
            {{"a"}, "a"}
    };

    Solution s;
    for (auto &p: test_cases) {
        auto r = s.longestCommonPrefix(p.first);
        if(r == p.second)
            cout << "ok " << "exp:" << p.second << " out:" << r << endl;
        else
            cout << "no " << "exp:" << p.second << " out:" << r << endl;
    }

    return 0;
}
