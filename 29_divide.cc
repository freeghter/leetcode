//
// Created by ft on 2018/9/15.
//
/**
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 *
 * 示例 1:
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 *
 * 示例 2:
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 *
 * 说明:
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == INT_MAX)
            return -1;
        if(dividend == INT_MAX && divisor == INT_MIN)
            return 0;
        if((dividend == INT_MAX && divisor == INT_MAX) || (dividend == INT_MIN && divisor == INT_MIN))
            return 1;

        bool f1= dividend < 0;
        bool f2= divisor < 0;
        int dividend_left = 0;
        if(dividend == INT_MIN) {
            dividend = INT_MAX;
            dividend_left = 1;
        }
        else
            dividend = abs(dividend);
        if(divisor == INT_MIN)
            divisor = INT_MAX;
        divisor = abs(divisor);

        if(dividend < divisor)
            return 0;

        int r = 0;
        while (dividend >= divisor) {
            int t = divisor, p = 1;         // t是p个divisor的大小
            while ( (t << 1) > 0 && dividend >= (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            r += p;
            dividend -= t;
            if(dividend_left > 0){
                dividend += dividend_left;
                dividend_left = 0;
            }
        }

        return f1 ^ f2 ? -r: r;
    }
};

int main(int argc, char * argv[]){

    vector<pair<pair<int, int>,int>> test_cases{
            {{-2147483648, 1}, -2147483648}
    };

    Solution s;
    for (auto p: test_cases){
        auto r = s.divide(p.first.first, p.first.second);
        if(r == p.second){
            cout << "ok " << "exp:" << p.second << " out:" << r << endl;
        }else{
            cout << "no " << "exp:" << p.second << " out:" << r << endl;
        }
    }
    return 0;
}
