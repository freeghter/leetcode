//
// Created by ft on 2018/9/25.
//
/**
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 示例 1:
 * 输入:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出: 3
 *
 * 解释:
 * 长度最长的公共子数组是 [3, 2, 1]。
 * 说明:
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));

        int r = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if(A[i] == B[j]){
                    if(i > 0 && j > 0)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 1;
                }else
                    dp[i][j] = 0;
                r = r > dp[i][j] ? r : dp[i][j];
            }
        }

        return r;
    }
};

int main(int argc, char * argv[]){
    vector<int> A={0, 1, 1, 1, 1};
    vector<int> B={1, 0, 1, 0, 1};

    Solution s;
    auto r = s.findLength(A, B);
    cout << r << endl;
    return 0;
}