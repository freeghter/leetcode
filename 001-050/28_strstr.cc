//
// Created by ft on 2018/9/15.
//
/**
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
 * 如果不存在，则返回  -1。
 *
 * 示例 1:
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 *
 * 示例 2:
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 说明:
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.empty())
            return 0;

        vector<int> next = make_prefix(needle);
        make_next(next);

        for (int i = 0, j = 0; i < haystack.size();) {
            if(j==needle.size()-1 && haystack[i] == needle[j]){
                return i - j;
            }
            if(haystack[i] == needle[j]){
                ++i;
                ++j;
            }else if(next[j] == -1){
                ++i;
            }else{
                j = next[j];
            }
        }
        return -1;
    }

private:
    vector<int> make_prefix(const string &pattern){
        vector<int> prefix(pattern.size(), 0);

        for (int i = 1, len = 0; i < pattern.size();) {
            if(pattern[len] == pattern[i]) {
                prefix[i] = ++len;
                ++i;
            }else if(len > 0){
                len = prefix[len-1];
            }else{
                prefix[i] = 0;
                ++i;
            }
        }
        return prefix;
    }

    void make_next(vector<int> &prefix){
        for (int i = prefix.size()-1; i > 0 ; --i)
            prefix[i] = prefix[i-1];
        prefix[0] = -1;
    }
};

int main(int argc, char * argv[]){

    Solution s;
    int pos = s.strStr("ABABCABAA", "ABCAB");
    cout << pos << endl;
    return 0;
}