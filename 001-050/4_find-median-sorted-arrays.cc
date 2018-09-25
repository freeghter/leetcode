//
// Created by ft on 2018/9/2.
//
/**
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
 * 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
 * 你可以假设 nums1 和 nums2 不同时为空。
 *
 * 示例 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 中位数是 2.0
 *
 * 示例 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 中位数是 (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        for (auto t1=nums1.begin(), t2=nums2.begin(); t1!=nums1.end() || t2!= nums2.end() ;) {
            int min = 0;
            if(t1 != nums1.end() && t2 != nums2.end()){
                if(*t1 < *t2){
                    min = *t1;
                    t1++;
                }else{
                    min = *t2;
                    t2++;
                }
            }else{
                if(t1 != nums1.end()) {
                    min = *t1;
                    t1++;
                }
                else{
                    min = *t2;
                    t2++;
                }
            }
            temp.push_back(min);
        }
        if(temp.size() % 2 == 1){
            return temp[temp.size()>>1];
        }
        return (temp[(temp.size()>>1) - 1] + temp[temp.size()>>1]) /2.0;
    }
};

int main(int argc, char * argv[]){
    Solution s;
    vector<int> v1,v2;
    
    v1 = {1,3};
    v2 = {2};
    double r = s.findMedianSortedArrays(v1, v2);
    cout << r << endl;

    v1 = {1, 2};
    v2 = {3, 4};
    r = s.findMedianSortedArrays(v1, v2);
    cout << r << endl;
    return 0;
}