//
// Created by ft on 2018/9/29.
//
/**
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
            bool flag = false;
            for(int j=index; j < i; ++j) {
                if (nums[j] == nums[i])
                    flag = true;
            }
            if(flag)
                continue;

            swap(nums[index], nums[i]);
            permute_core(nums, index+1, out);
            swap(nums[index], nums[i]);
        }
    }
};

int main(int argc, char * argv[]){
    vector<int> data = {2,2,1,1};

    Solution s;
    auto  vecs = s.permuteUnique(data);
    for (auto vec: vecs) {
        for(auto i: vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}