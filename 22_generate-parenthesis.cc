//
// Created by ft on 2018/9/12.
//
/**
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 例如，给出 n = 3，生成结果为：
 * [
 * "((()))",
 * "(()())",
 * "(())()",
 * "()(())",
 * "()()()"
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        generate(r, "", 0, 0, n);
        return r;
    }

private:
    void generate(vector<string> &r, const string &cur, int open, int close, int max){
        if(cur.size() >= max * 2) {
            r.push_back(cur);
            return;
        }

        if(open < max)
            generate(r, cur+"(", open+1, close, max);
        if(close < open)
            generate(r, cur+")", open, close+1, max);
    }
};

int main(int argc, char * argv[]){
    Solution s;
    auto r = s.generateParenthesis(3);
    for (auto &str:r)
        cout << str << endl;
    return 0;
}
