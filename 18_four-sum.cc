//
// Created by ft on 2018/9/10.
//
/**
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 *
 * 注意：
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 满足要求的四元组集合为：
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 *  ]
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> t;
        int temp = 1;
        vector<vector<int>> r;

        if(nums.size() < 4)
            return r;

        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool{return a<b;});
        for (int i = 0; i < nums.size() - 3; i += temp) {
            for (int j = i + 1; j < nums.size()-2; j += temp) {
                for (int begin = j+1, end = nums.size()-1; begin < end;) {
                    int sum = nums[i] + nums[j] + nums[begin] + nums[end];
                    if(sum == target){
                        t = {nums[i], nums[j], nums[begin], nums[end]};
                        r.push_back(t);
                        for (temp = 1; begin+temp < nums.size() && nums[begin+temp] == nums[begin]; ++temp);
                        begin += temp;
                        for (temp = 1; end -temp >= begin && nums[end-temp] == nums[end]; ++temp);
                        end -= temp;
                    }else if(sum < target)
                        ++begin;
                    else
                        --end;
                }
                for (temp = 1; j+temp < nums.size() && nums[j+temp] == nums[j]; ++temp);
            }
            for (temp = 1; i+temp<nums.size() && nums[i+temp] == nums[i]; ++temp);
        }
        return r;
    }
};

int main(int argc, char * argv[]){

    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};

    Solution s;
    auto r = s.fourSum(nums, -11);
    for (auto t: r){
        for(auto i: t)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
