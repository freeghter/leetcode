//
// Created by ft on 2018/9/5.
//
/**
 * 判断一个整数是否是回文数。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 * 输入: 121
 * 输出: true
 *
 * 示例 2:
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 * 示例 3:
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 * 进阶:
 * 你能不将整数转为字符串来解决这个问题吗？
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int t = x;
        vector<int> v;
        while(t){
            v.push_back(t % 10);
            t /= 10;
        }

        t = 0;
        for(int i: v)
            t = t*10 + i;

        return x == t;
    }

    // 官方答案
    bool is_palindrome(int x){
        if(x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int t = 0;
        while(t < x){
            t = t*10 + x%10;
            x /= 10;
        }
        return x == t || x == t/10;
    }
};

int main(int argc, char * argv[]){
    vector<pair<int,bool>> test_cases={
            {121, true},
            {-121, false},
            {10, false}
    };

    Solution s;
    for(auto p: test_cases){
        auto r = s.is_palindrome(p.first);
        if(p.second == r){
            cout << "ok: " << "res: " << r << " expected: " << p.second << endl;
        }else{
            cout << "no: " << "res: " << r << " expected: " << p.second << endl;
        }
    }

    return 0;
}
