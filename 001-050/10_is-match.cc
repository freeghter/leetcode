//
// Created by ft on 2018/9/5.
//
/**
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的元素。
 * 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 *
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 *
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
 *
 * 示例 3:
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 *
 * 示例 4:
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 *
 * 示例 5:
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }

private:
    bool match(const char * s, const char * p){
        if(s[0] == '\0' && p[0] =='\0')
            return true;

        if(s[0] != '\0' && p[0] == '\0')
            return false;

        // 模式串的下一个字符不是*
        if(p[1] != '*'){
            if(s[0] == 0 || (s[0] != p[0] && p[0] != '.')) // 当前字符不匹配
                return false;
            return match(s+1, p+1);
        }

        // 模式串的下一个字符是*
        if(s[0] != p[0] && p[0] != '.')     // 当前字符不匹配
            return match(s, p+2);
        if(s[0] == '\0')
            return match(s, p+2);
        return match(s+1, p) || match(s + 1, p + 2) ||  match(s, p+2) ;
    }
};

int main(int argc, char * argv[]){

    vector<pair<pair<string,string>, bool>> test_cases = {
            {{"acaabbaccbbacaabbbb","a*.*b*.*a*aa*a*"}, false},
            {{"bcbbabab",".*a*a"}, false},
            {{"","c*c*"}, true},
            {{"a","ab*"}, true},
            {{"aa", "a*"}, true},
            {{"ab", ".*"}, true},
            {{"aa", "a"}, false},
            {{"aab", "c*a*b"}, true},
            {{"mississippi", "mis*is*p*."}, false}
    };

    Solution s;
    for (auto p: test_cases){
        auto r = s.isMatch(p.first.first, p.first.second);
        if(r == p.second){
            cout << "ok " << "000-000:" << p.second << " out:" << r << endl;
        }else{
            cout << "no " << "000-000:" << p.second << " out:" << r << endl;
        }
    }

    return 0;
}