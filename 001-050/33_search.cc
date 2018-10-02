//
// Created by ft on 2018/9/30.
//
/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {


        for (int begin = 0, end = nums.size()-1; begin <= end;) {
            int mid = (begin + end) >> 1;
            if(nums[mid] == target)
                return mid;
            // 在前半部分
            if((nums[begin] <= target && nums[mid] >= target) ||
                    (nums[begin] <= target && nums[mid] <= target && nums[begin] > nums[mid]) ||
                    (nums[begin] >= target && nums[mid] >= target && nums[mid] < nums[begin]))
                end = mid - 1;
            else
                begin = mid + 1;
        }

        // 递增
        for (int begin = 0, end = nums.size()-1; begin <= end;) {
            int mid = (begin + end) >> 1;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        // 递减
        for(int begin = 0, end = nums.size()-1; begin <= end;){
            int mid = (begin+end) >> 1;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                end = mid -1;
            else
                begin = mid + 1;
        }
        return - 1;
    }
};

int main(int argc, char *argv[]) {

//    vector<int> data={4,5,6,7,0,1,2}; 0
    vector<int> data = {5, 1, 2, 3, 4}; // 1
    Solution s;
    int pos = s.search(data, 1);
    cout << pos << endl;
    return 0;
}