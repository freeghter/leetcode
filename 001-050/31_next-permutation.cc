//
// Created by ft on 2018/9/23.
//
/**
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须原地修改，只允许使用额外常数空间。
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int pos = nums.size() - 1;

        for (; pos > 0 && nums[pos-1] >= nums[pos]; --pos);

        if(pos==0){
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse(nums.begin()+pos,nums.end());
        int j = pos;
        for (j; j < nums.size() && nums[j] <= nums[pos-1]; ++j);
        swap(nums[j], nums[pos-1]);
    }
};

int main(int argc, char * argv[]){
    Solution s;
    vector<int> v={0,1,1,0,4,4};
    s.nextPermutation(v);
    for (auto i: v)
        cout << i << " ";
    return 0;
}