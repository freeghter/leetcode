//
// Created by ft on 2018/8/29.
//
/**
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 *
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 *
 * 输入: 2.10000, 3
 * 输出: 9.26100
 *
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2-2 = 1/22 = 1/4 = 0.25
 *
 * 说明:
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
 */
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, long long int n) {
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;

        if(n == 1)
            return x;

        if(n > 1){
            double r = myPow(x, n >> 1);
            return n%2 == 0 ? r*r : x*r*r;
        }else {
            double r = myPow(x, abs(n));
            return 1 / r;
        }
    }

};

int main(int argc, char * argv[]){
    Solution s;
    auto r = s.myPow(1.0, 2147483648);
    cout << r << endl;
    return 0;
}