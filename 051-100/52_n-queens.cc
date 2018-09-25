//
// Created by ft on 2018/9/25.
//
/**
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案的数量。
 *
 * 示例:
 * 输入: 4
 * 输出: 2
 * 解释: [
 * [".Q..",  // 解法 1
 *  "...Q",
 *  "Q...",
 *  "..Q."],
 *  ["..Q.",  // 解法 2
 *  "Q...",
 *  "...Q",
 *  ".Q.."]
 *  ]
 *  解释: 4 皇后问题存在两个不同的解法。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;

        vector<int> v;
        v.reserve(n);
        for(int i=0; i<n; ++i)
            v.push_back(i);

        n_queens(v, 0, total);
        return total;
    }

private:
    bool check_valid(const vector<int> &v){
        int len = v.size();
        for (int i = 0; i < len - 1; ++i) {
            for (int j = i+1; j < len; ++j) {
                if(i-j == v[i]-v[j] || i-j == v[j] - v[i])
                    return false;
            }
        }
        return true;
    }

    void n_queens(vector<int> &pos, int index, int &total){
        if(index == pos.size()-1){
//            for (auto i: pos)
//                cout << i << " ";
//            cout << endl;
            if(check_valid(pos))
                ++total;
        }else{
            for(int i=index; i < pos.size(); ++i){
                swap(pos[i], pos[index]);
                n_queens(pos, index+1, total);
                swap(pos[i], pos[index]);
            }
        }
    }
};

int main(int argc, char  * argv[]){
    Solution s;
    int total = s.totalNQueens(4);
    cout << total << endl;
    return 0;
}