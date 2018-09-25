//
// Created by ft on 2018/9/4.
//
/**
 * 给定一个 32 位有符号整数，将整数中的数字进行反转。
 * 注意:
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
 * 根据这个假设，如果反转后的整数溢出，则返回 0。
 *
 * 示例 1:
 * 输入: 123
 * 输出: 321
 * 示例 2:
 *
 * 输入: -123
 * 输出: -321
 * 示例 3:
 *
 * 输入: 120
 * 输出: 21
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        x = x > 0 ? x : -x;

        int r {0};
        do{
            int t = r * 10 + x % 10;
            if(t / 10 != r)
                return 0;
            r = r*10 + x % 10;
        }while(x /= 10);

        r = negative ? -r : r;
        return r;
    }
};

int main(int argc, char * argv[]){
    vector<pair<int,int>> test_cases={
            {1534236469, 0},{123, 321},{-123, -321},{120,21},{INT_MIN, 0}
    };

    Solution s;
    for(auto p: test_cases){
        int r = s.reverse(p.first);
        if(r == p.second){
            cout << "true:" << r << " " << p.second << endl;
        }else{
            cout << "false:" << r << " " << p.second << endl;
        }
    }

    return 0;
}
