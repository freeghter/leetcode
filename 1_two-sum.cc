//
// Created by ft on 2018/8/29.
//
/**
 * 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 * 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 *
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r;

        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    r.push_back(i);
                    r.push_back(j);
                }
            }
        }

        return r;
    }
};

int main(int argc, char * argv[]){
    vector<int> v={2, 7, 11, 15};
    Solution s;
    auto r = s.twoSum(v, 9);
    for (auto i: r)
        cout << i << " ";
    return 0;
}