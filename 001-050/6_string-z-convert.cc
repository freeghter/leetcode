//
// Created by ft on 2018/9/4.
//
/**
 * 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * 之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
 * 实现一个将字符串进行指定行数变换的函数:
 * string convert(string s, int numRows);
 *
 * 示例 1:
 * 输入: s = "PAYPALISHIRING", numRows = 3
 * 输出: "PAHNAPLSIIGYIR"
 *
 * 示例 2:
 * 输入: s = "PAYPALISHIRING", numRows = 4
 * 输出: "PINALSIGYAHRPI"
 * 解释:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string r;
        vector<vector<char>> t(numRows, vector<char>());
        bool asc = true;
        int index = 0;
        for(auto c: s){
            t[index].push_back(c);
            asc ? ++index: --index;
            if(index == -1 || index == numRows)
                asc = !asc;
            if(index == -1)
                index = 1;
            if(index == numRows)
                index = numRows - 2;
        }
        for(auto s: t)
            for(auto c: s)
                r.push_back(c);
        return r;
    }
};

int main(int argc, char * argv[]){

    vector<pair<string,int>> test_cases={
            {"PAYPALISHIRING", 3},
            {"PAYPALISHIRING", 4}};

    Solution s;
    for (auto p: test_cases) {
        cout << s.convert(p.first, p.second) << endl;
    }
    return 0;
}