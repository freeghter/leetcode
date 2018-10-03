//
// Created by ft on 2018/10/2.
//
/**
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> r = {-1, -1};
        if (nums.empty()) {
            return r;
        }

        for (int begin = 0, end = nums.size(); begin <= end;) {
            int mid = (begin + end) >> 1;
            if (nums[mid] == target && ((mid > 0 && nums[mid - 1] < target) || mid == 0)) {
                r[0] = mid;
                break;
            }

            if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        for (int begin = 0, end = nums.size(); begin <= end;) {
            int mid = (begin + end) >> 1;
            if (nums[mid] == target && ((mid < nums.size() - 1 && nums[mid + 1] > target) || mid == nums.size() - 1)) {
                r[1] = mid;
                break;
            }
            if (nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        return r;
    }
};

int main(int argc, char *argv[]) {
    vector<int> data = {-1};
    Solution s;
    auto r = s.searchRange(data, 0);
    cout << r[0] << " " << r[1];
}