//
// Created by ft on 2018/9/6.
//
/**
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
 * 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
 * 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 *
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 *
 * 示例 1:
 * 输入: "III"
 * 输出: 3
 *
 * 示例 2:
 * 输入: "IV"
 * 输出: 4
 *
 * 示例 3:
 * 输入: "IX"
 * 输出: 9
 *
 * 示例 4:
 * 输入: "LVIII"
 * 输出: 58
 * 解释: C = 100, L = 50, XXX = 30, III = 3.
 *
 * 示例 5:
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 *
 * {1000, "M"},
 * {900, "CM"},
 * {500, "D"},
 * {400, "CD"},
 * {100, "C"},
 * {90, "XC"},
 * {50, "L"},
 * {40, "XL"},
 * {10, "X"},
 * {9, "IX"},
 * {5, "V"},
 * {4, "IV"},
 * {1, "I"},
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.size();) {
            if(s.compare(i, 1, "M") == 0) {
                num += 1000;
                ++i;
            }
            if(s.compare(i, 2, "CM") == 0){
                num += 900;
                i+=2;
            }
            if(s.compare(i, 1, "D") == 0){
                num += 500;
                i+=1;
            }
            if(s.compare(i, 2, "CD") == 0){
                num += 400;
                i+=2;
            }
            if(s.compare(i, 1, "C") == 0){
                num += 100;
                ++i;
            }
            if(s.compare(i, 2, "XC") == 0){
                num += 90;
                i+=2;
            }
            if(s.compare(i, 1, "L") == 0){
                num += 50;
                ++i;
            }
            if(s.compare(i, 2, "XL") == 0){
                num += 40;
                i+=2;
            }
            if(s.compare(i, 1, "X") == 0){
                num += 10;
                i+=1;
            }
            if(s.compare(i, 2, "IX") == 0){
                num += 9;
                i+=2;
            }
            if(s.compare(i, 1, "V") == 0){
                num += 5;
                i+=1;
            }
            if(s.compare(i, 2, "IV") == 0){
                num += 4;
                i+=2;
            }
            if(s.compare(i, 1, "I") == 0){
                num += 1;
                i+=1;
            }
        }
        return num;
    }
};

int main(int argc, char * argv[]){

    vector<pair<string, int>> test_cases={
            {"MCMXCIV", 1994},
            {"III", 3},
            {"IV", 4},
            {"IX", 9},
            {"LVIII", 58}
    };

    Solution s;
    for (auto &p: test_cases) {
        auto r = s.romanToInt(p.first);
        if(r == p.second)
            cout << "ok " << "exp:" << p.second << " out:" << r << endl;
        else
            cout << "no " << "exp:" << p.second << " out:" << r << endl;
    }


    return 0;
}