//
// Created by ft on 2018/9/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int r = target - INT_MAX;
        sort(nums.begin(), nums.end(), [](int a, int b) ->bool{return a < b;});
        for(int i=0; i<nums.size(); i++){
            for(int begin = i+1, end = nums.size()-1; begin < end;){
                if( nums[i] + nums[begin] + nums[end] == target){
                    return target;
                }

                if(abs(target - (nums[i] + nums[begin] + nums[end])) < abs(target - r))
                    r = nums[i] + nums[begin] + nums[end];

                if(nums[begin] + nums[end] + nums[i] < target){
                    begin++;
                }else
                    end--;
            }
        }

        return r;
    }
};

int main(int argc, char * argv[]){
    vector<int> v={-3, -2, -5, 3, -4};

    Solution s;
    int r = s.threeSumClosest(v, -1);
    cout << r << endl;
    return 0;
}
