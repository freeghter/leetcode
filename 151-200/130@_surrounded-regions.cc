//
// Created by ft on 2018/8/26.
//
/**
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * 运行函数后
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 * 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
 * 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
    }
};

class Solution_others {
public:
    vector<int>  unionset;
    vector<bool> isedge;
    void solve(vector<vector<char>>& board) {

        if(board.size()==0||board[0].size()==0)
            return;

        int width =board[0].size();
        int length = board.size()*width;
        unionset = vector<int>(length,0);
        isedge = vector<bool>(length,false);

        for(int i=0;i<length;i++){
            unionset[i]=i;
            int x=i/width , y=i%width;
            if((board[x][y]=='O')&&((x==0)||(x==board.size()-1)||(y==0)||(y==board[0].size()-1)))
                isedge[i]=true;
        }

        for(int j=0;j<length;j++){
            int x=j/width, y=j%width;
            int down = x+1, right = y+1;
            if(down<board.size()&&board[x][y]==board[down][y])
                unionS(j,j+width);
            if(right<board[0].size()&&board[x][y]==board[x][right])
                unionS(j,j+1);
        }

        for(int m=0;m<length;m++){
            int x=m/width,y=m%width;
            if(board[x][y]=='O'&&!isedge[find(m)])
                board[x][y]='X';
        }

    };
    void unionS(int m,int n){
        int rootM=find(m);
        int rootN=find(n);
        if(rootM==rootN)return;
        unionset[rootN] = rootM;
        if(isedge[rootN])
            isedge[rootM]=true;
    };

    int find(int p){
        while(p!=unionset[p]){
            unionset[p]=unionset[unionset[p]];
            p=unionset[p];
        }
        return p;
    };
};

int main(int argc, char * argv[]){
    return 0;
}
