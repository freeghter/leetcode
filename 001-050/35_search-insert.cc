//
// Created by ft on 2018/10/3.
//
/**
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty() || nums[0] > target)
            return 0;

        for (int begin = 0, end = nums.size() - 1; begin <= end;) {
            int mid = (begin + end) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target && (nums.size() - 1 == mid || nums[mid + 1] > target))
                return mid + 1;
            else if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return nums.size();
    }
};

int main(int argc, char *argv[]) {
    vector<pair<pair<vector<int>, int>, int>> test_cases = {
            {{{1, 3, 5, 6}, 2}, 1},
            {{{1, 3, 5, 6}, 5}, 2}
    };

    Solution s;
    for (auto p: test_cases) {
        auto r = s.searchInsert(p.first.first, p.first.second);
        if (r == p.second)
            cout << "ok" << endl;
        else
            cout << "no: " << "exp " << p.second << " res " << r << endl;
    }
    return 0;
}