//
// Created by ft on 2018/9/8.
//
/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r;

        for (auto c:digits) {
            // 开头的字符
            char begin = 0;
            int n = 3;
            switch (c){
                case '7':
                    begin = 'p'; n = 4; break;
                case '8':
                    begin = 't'; break;
                case '9':
                    begin = 'w'; n = 4; break;
                default:
                    begin= static_cast<char>((c - '2') * 3 + 'a');break;
            }
            vector<string> t(r);
            r.clear();
            if(t.empty()){
                for(int i=0; i < n; i++) {
                    r.push_back(string("")+(char)(begin+i));
                }
            } else{
                for(int i=0; i < n; ++i){
                    for(auto s: t)
                        r.push_back(s+(char)(begin+i));
                }
            }
        }
        return r;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    auto r = s.letterCombinations("7");
    for(const auto &str: r)
        cout << str << " ";
    return 0;
}
