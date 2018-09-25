//
// Created by ft on 2018/9/6.
//
/**
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> t;

        sort(nums.begin(), nums.end(), [](int a, int b)->bool{return a < b;});

        for (int i = 0; i < nums.size(); ++i) {
            if(i-1 >= 0 && nums[i] == nums[i-1]) // 为了去重
                continue;

            for (int j = nums.size() - 1; j > i + 1; --j) {
                if(j + 1 < nums.size() && nums[j] == nums[j+1]) // 为了去重
                    continue;

                int target = 0 - nums[i] - nums[j];
                if(binary_search(nums.begin() + i + 1, nums.begin() + j, target)){
                    t.push_back(nums[i]);
                    t.push_back(target);
                    t.push_back(nums[j]);
                    r.push_back(t);
                    t.clear();
                }
            }
        }
        return r;
    }
};

int main(int argc, char * agv[]){
    vector<int> nums = {0,0,0,0};

    Solution s;
    auto r = s.threeSum(nums);
    for (auto p: r) {
        for (auto i: p) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}