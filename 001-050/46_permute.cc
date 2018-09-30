//
// Created by ft on 2018/9/29.
//
/**
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 *
 * 示例:
 * 输入: [1,2,3]
 * 输出:
 * [
 * [1,2,3],
 * [1,3,2],
 * [2,1,3],
 * [2,3,1],
 * [3,1,2],
 * [3,2,1]
]
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        permute_core(nums, 0, r);
        return r;
    }

private:
    void permute_core(vector<int> &nums, int index, vector<vector<int>> &out){
        if(index == nums.size()){
            out.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            permute_core(nums, index+1, out);
            swap(nums[index], nums[i]);
        }
    }
};

int main(int argc, char * argv[]){

    vector<int> data = {1,2,3};

    Solution s;
    auto  vecs = s.permute(data);
    for (auto vec: vecs) {
        for(auto i: vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
