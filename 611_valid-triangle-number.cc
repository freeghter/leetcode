/**
 * 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
 *
 * 示例 1:
 * 输入: [2,2,3,4]
 * 输出: 3
 * 解释:
 * 有效的组合是:
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 首先想出来的方法 这个方法会超时
    int triangleNumber_1(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if(nums[i] + nums[j] > nums[k] &&
                    nums[i] + nums[k] > nums[j] &&
                    nums[k] + nums[j] > nums[i])
                        ++count;
                }
            }
        }
        return count;
    }

    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool{ return a < b;});
        for(int i=nums.size()-1; i >= 2; i--){
            int left = 0;
            int right = i-1;

            while (left < right){
                // 找到了第二条边，总数加上第一条边的可能性，然后更新第二条边位置
                if(nums[right] - nums[left] < nums[i] && nums[right] + nums[left] > nums[i]){
                    count += (right-left);
                    right--;
                }
                else if(nums[right] - nums[left] > nums[i])
                    right--;
                else
                    left++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> v = {2, 2, 3, 4};
    int r = s.triangleNumber(v);
    cout << r << endl;
    return 0;
}