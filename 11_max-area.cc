//
// Created by ft on 2018/9/5.
//
/**
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 *
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() -1;
        int max = 0;
        int len = height.size() - 1;
        for(; i <= j; --len){
            int val = height[i] < height[j] ? height[i] * len: height[j]*len;
            max = val > max ? val : max;
            height[i] < height[j] ? ++i : --j;
        }

        return max;
    }
};

int main(int argc, char * argv[]){
    vector<pair<vector<int>, int>> test_cases={
            {{1,8,6,2,5,4,8,3,7}, 49}
    };

    Solution s;
    for (auto &p: test_cases) {
        auto r = s.maxArea(p.first);
        if(r == p.second)
            cout << "ok " << "exp:" << p.second << " out:" << r << endl;
        else
            cout << "no " << "exp:" << p.second << " out:" << r << endl;
    }
}