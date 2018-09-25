//
// Created by ft on 2018/9/24.
//
/**
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * 示例:
 * 输入: 4
 * 输出: [
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
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos;

        pos.reserve(n);
        for (int i = 0; i < n; ++i)
            pos.push_back(i);

        vector<vector<int>> t;
        n_queen(pos, 0, t);

        vector<vector<string>> r;
        make_result(t, r, n);
        return r;
    }

private:
    void make_result(vector<vector<int>> in, vector<vector<string>> &out, int n){
        for(auto v: in){
            vector<string> s;
            for(auto i: v){
                string str;
                for (int j = 0; j < n; ++j)
                    str += (i == j) ? "Q" : ".";
                s.push_back(str);
            }
            out.push_back(s);
        }
    }

    void n_queen(vector<int> &pos, int index, vector<vector<int>> &r){
        int len = pos.size();

        // 如果是一个排列则检查该排列是否满足要求
        if(index == len-1){
//            for (auto i: pos)
//                cout << i << " ";
//            cout << endl;
            if(check_valid(pos))
                r.push_back(pos);
        }
        else{
            for (int i = index; i < len; ++i) {
                swap(pos[index], pos[i]);
                n_queen(pos, index+1, r);
                swap(pos[index], pos[i]);
            }
        }
    }
    /**
     * 检查排列是否符合要求
     * @param pos
     * @return
     */
    bool check_valid(const vector<int> &pos){
        int len = pos.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if((j-i == pos[j] -  pos[i]) ||
                        (j-i == pos[i] - pos[j])) // 对角线冲突
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char * argv[]){
    Solution s;
    auto r = s.solveNQueens(5);
    for(const auto &v: r){
        for(const auto &str: v){
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}