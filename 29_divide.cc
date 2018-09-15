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

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool f1= dividend < 0;
        bool f2= divisor < 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        if(dividend < divisor)
            return 0;

        int r = 0;
        while (dividend >= divisor) {
            long long t = divisor, p = 1;
            while (dividend >= (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            r += p;
            dividend -= t;
        }

        return f1 ^ f2 ? -r: r;
    }
};

int main(int argc, char * argv[]){
    Solution s;
    int r = s.divide(2147483647, 2);
    cout << r << endl;
    return 0;
}
